#include <stdlib.h>
#include <string.h>

char partition(char* buf, char* expr1, char* expr2)
{
	char sign = '+';
	int parenthesis = 0,
		i1 = 0,
		i2 = 0,
		j = 0;
	
	// удаляем лишние скобки в начале и в конце
	for (int i = 0; i < strlen(buf); i++)
		buf[i] = buf[i + 1];
	buf[strlen(buf) - 1] = '\0';

	// записываем первый аргумент
	if (buf[0] != '(')
		for (; buf[j] >= 48 && buf[j] <= 57; j++, i1++)
			expr1[i1] = buf[j];
	else
	{
		for (int k = 0; !(buf[k] >= 48 && buf[k] <= 57); k++)
			parenthesis++;
		for (; parenthesis; j++, i1++)
		{
			expr1[i1] = buf[j];
			if (buf[j] == ')')
				parenthesis--;
		}
	}
	expr1[i1] = '\0';

	// записываем арифметический знак
	sign = buf[j++]; 

	// записываем второй аргумент
	for (; buf[j]; j++, i2++)
		expr2[i2] = buf[j];
	expr2[i2] = '\0';
	
	return sign;
}

int eval(char* buf)
{
	if (buf[0] != '(') // если добрались до цифры
		return atoi(buf);
	
	char a1[256]{}, a2[256]{};
	char op = '+';
	
	op = partition(buf, a1, a2);
		
	switch (op)
	{
	case '+':
		return eval(a1) + eval(a2);
	case '-':
		return eval(a1) - eval(a2);
	case '/':
		return eval(a1) / eval(a2);
	case '*':
		return eval(a1) * eval(a2);
	default:
		return 0;
	}
}
