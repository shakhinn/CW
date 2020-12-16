.MODEL FLAT, C
.CODE

func PROC 

push ebp
mov ebp, esp

mov eax, [ebp + 8]            ;массив псевдослучайных чисел
mov ebx, [ebp + 16]           ;массив результирующего распределения
mov ecx, [ebp + 18]           ;счетчик цикла
inc ecx
mov esi, 0
;mov edx, 1
CYCLE:
mov edi,[eax+4*esi]   ;запись i-го элемента из массива псевдослучайных чисел
sub edi, [ebp + 12] ;вычисление индекса отрезка в массиве распределения, соответствующего данному элементу
mov edx, [ebx+4*edi]
inc edx
mov [ebx+4*edi], edx
inc esi
loop CYCLE
pop ebp
ret
func ENDP
END