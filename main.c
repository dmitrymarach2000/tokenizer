#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Token
{
	int pos;
	char *str;
};

int main()
{

	int ch;
	int i = 0;
	char *buf_str;
	int buf_pos;
	struct Token *tokens = (struct Token *)malloc(0);
	int token_n = 0;
	char new_wrd = 1;
	char last_word = 1;
	while ((ch = getchar()) != '\n')
	{
		printf("\n~'%c'", ch);
		i++;
		if (
			ch != '\n' &&
			ch != '\t' &&
			ch != '\r' &&
			ch != ' '	)
		{

			if (new_wrd)
			{
				printf("^\n");
				last_word = 1;
				new_wrd = 0;
				buf_str = (char *)malloc(1 * sizeof(char));
				buf_pos = i;
			}
			else
			{
				printf("*\n");
				buf_str = (char *)realloc(buf_str, ((i - buf_pos) + 1) * sizeof(char));
			}
			buf_str[i - buf_pos] = ch;
		}
		else
		{
			if (!new_wrd)
			{
				new_wrd = 1;
				buf_str = (char *)realloc(buf_str, ((i - buf_pos) + 1) * sizeof(char));
				buf_str[i - buf_pos] = '\0';
				printf("word'%s'", buf_str);
				if (1)
				{ //Вставить проверку токена
					tokens = (struct Token *)realloc(tokens, ++token_n);
					tokens[token_n - 1].pos = buf_pos;
					tokens[token_n - 1].str = (char *)malloc(((i - buf_pos) + 1) * sizeof(char));
					strcpy(tokens[token_n - 1].str, buf_str);
				}
			}
			else
			{
				last_word = 0;
			}
		}
	}
	if (last_word)
	{
		printf("\n=\n");
		buf_str = (char *)realloc(buf_str, ((i - buf_pos) + 1) * sizeof(char));
		buf_str[i - buf_pos] = '\0';
		if (1)
		{ //Вставить проверку токена
			tokens = (struct Token *)realloc(tokens, ++token_n);
			tokens[token_n - 1].pos = buf_pos;
			tokens[token_n - 1].str = (char *)malloc(((i - buf_pos) + 1) * sizeof(char));
			strcpy(tokens[token_n - 1].str, buf_str);
		}
	}

	printf("\n\n");
	for (int i = 0; i < token_n; ++i)
	{
		printf("%d\t%s\n", tokens[i].pos, tokens[i].str);
	}
}
