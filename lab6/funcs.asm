.MODEL FLAT, C
.CODE

func PROC 

push ebp
mov ebp, esp

mov eax, [ebp + 8]            ;������ ��������������� �����
mov ebx, [ebp + 16]           ;������ ��������������� �������������
mov ecx, [ebp + 18]           ;������� �����
inc ecx
mov esi, 0
;mov edx, 1
CYCLE:
mov edi,[eax+4*esi]   ;������ i-�� �������� �� ������� ��������������� �����
sub edi, [ebp + 12] ;���������� ������� ������� � ������� �������������, ���������������� ������� ��������
mov edx, [ebx+4*edi]
inc edx
mov [ebx+4*edi], edx
inc esi
loop CYCLE
pop ebp
ret
func ENDP
END