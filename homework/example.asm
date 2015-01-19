assume cs:code

stack segment
	db 128 dup(0)
stack ends

code segment
start:		mov ax,stack			;	init stack
			mov ss,ax
			mov sp,128
			
			push cs					;	mov NI9 to 0:204
			pop ds
			mov si,offset ni9		
			mov ax,0				
			mov es,ax
			mov di,204H
			mov cx,offset ni9e - offset ni9
			cld
			rep movsb
			
			;	save BIOS origin int9
			push es:[9*4]			;	IP
			pop es:[200H]
			push es:[9*4+2]			;	CS
			pop es:[202H]
			
			;	set ni9 as int9
			cli
			mov word ptr es:[9*4],204H
			mov word ptr es:[9*4+2],0
			sti
			
			mov ax,4c00H
			int 21H
			
ni9:		push ax
			push es
			push bx
			push cx
			
			
			mov bx,0
			mov es,bx
			
			pushf					;	call BIOS origin int9
			call dword ptr es:[200H]
			
			in al,60H				;	get keyboard input from port 60H
			cmp al,9EH				;	cmp with "A" UP
			jne ni9r
			
			;	change screen color
			mov bx,0b800H
			mov es,bx
			mov bx,0
			mov cx,2000				;	2000 chars per page
lp:			mov byte ptr es:[bx],41H
			add bx,2
			loop lp
			
ni9r:		pop cx
			pop bx
			pop es
			pop ax
			iret
ni9e:		nop			
			
code ends

end start
