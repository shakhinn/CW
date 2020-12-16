.MODEL FLAT, C
.DATA
.CODE

func2 PROC 
push ebp
mov ebp, esp
push edi
push esi

mov eax,[ebp + 8]       ;исходный массив распределения
mov ebx,[ebp + 16]       ;конечный массив распределения
mov ecx, [ebp + 20]   
inc ecx
mov edx, [ebp + 12]       ;массив левых границ 
mov esi, [ebp + 24]     ;самая первая левая граница
mov edi,00000000h       ;счетчик, отвечающий за промежуток, в который нужно записывать 
jmp STEP

CYCLE:
	add edx,00000004h ;рассматриваем следующую левую границу
	inc edi
STEP:
	cmp edi, [ebp + 28]   ;если счетчик равен длине массива левых границ (точка попала в последниий промежуток)
	je STEP2
	cmp esi,[edx]     ;сравнение текущей точки со следующей левой границей
	jge CYCLE          ;если больше или равна, то сравниваем следующую точку
STEP2:
	dec edi
	mov edx, [eax]
	add [ebx+4*edi],edx ;добавление количества попаданий в промежуток,соответствующий данной точке
	add eax, 00000004h
	inc esi             ;инкрементирование точки
	mov edi,00000000h   ;обнуление счетчика, отвечающего за промежуток
	mov edx,[ebp + 12]
    loop STEP

	pop esi
	pop edi
	pop ebp
	ret
func2 ENDP
END
