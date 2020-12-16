.MODEL FLAT, C
.DATA
.CODE

func2 PROC 
push ebp
mov ebp, esp
push edi
push esi

mov eax,[ebp + 8]       ;�������� ������ �������������
mov ebx,[ebp + 16]       ;�������� ������ �������������
mov ecx, [ebp + 20]   
inc ecx
mov edx, [ebp + 12]       ;������ ����� ������ 
mov esi, [ebp + 24]     ;����� ������ ����� �������
mov edi,00000000h       ;�������, ���������� �� ����������, � ������� ����� ���������� 
jmp STEP

CYCLE:
	add edx,00000004h ;������������� ��������� ����� �������
	inc edi
STEP:
	cmp edi, [ebp + 28]   ;���� ������� ����� ����� ������� ����� ������ (����� ������ � ���������� ����������)
	je STEP2
	cmp esi,[edx]     ;��������� ������� ����� �� ��������� ����� ��������
	jge CYCLE          ;���� ������ ��� �����, �� ���������� ��������� �����
STEP2:
	dec edi
	mov edx, [eax]
	add [ebx+4*edi],edx ;���������� ���������� ��������� � ����������,��������������� ������ �����
	add eax, 00000004h
	inc esi             ;����������������� �����
	mov edi,00000000h   ;��������� ��������, ����������� �� ����������
	mov edx,[ebp + 12]
    loop STEP

	pop esi
	pop edi
	pop ebp
	ret
func2 ENDP
END
