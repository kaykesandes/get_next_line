#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);

	while (s[i] != '\0')
		i++;

	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i = 0;

	if (!s)   //Caso a string verificada seja null acaba aqui.
		return (0);

	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);  //Retorna o ponteiro para o final da string caso o c seja um NULL.
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);  //Retorna o ponteiro até onde a gente encontra o caracter de escape.
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left_str || !buff)
		return (NULL);
	
	str = malloc(sizeof(char) * (ft_strlen(left_str) + ft_strlen(buff) + 1)); //Faz alocação dinamica que vai caber tanto left quanto buff
	if (str == NULL) //saida caso os 2 argumentos sejam null
		return (NULL);

	i = 0;
	while (left_str[i] != '\0')  //faz alocação do primeiro argumento da nossa função
	{
		str[i] = left_str[i];
		i++;
	}

	j = 0;
	while (buff[j] != '\0') //Faz a alocação do segundo argumento da nossa função
	{
		str[i] = buff[j];
		i++;
		j++;
	}
	str[i] = '\0'; //aloca no final o '\0'

	free(left_str); //limpa a memoria 
	return (str);
}


char	*ft_get_line(char *left_str)
{
	int		i;
	char	*str;

	i = 0;

	if (!left_str[i]) //verifica se left_str e null
		return (NULL);

	while (left_str[i] && left_str[i] != '\n') //encontra o ultimo indice 
		i++;

	str = (char *)malloc(sizeof(char) * (i + 2)); //faz alocação de memoria
	if (!str) //caso str seja 0 termina aq
		return (NULL);

	i = 0;
	while (left_str[i] && left_str[i] != '\n') //copia a linha até encontrar o \n
	{
		str[i] = left_str[i];
		i++;
	}

	if (left_str[i] == '\n') //avançar o indicie 
	{
		str[i] = left_str[i];
		i++;
	}

	str[i] = '\0'; //fecha nossa str
	return (str);
}

char	*ft_new_left_str(char *left_str)  //Incompleta
{
	int		i;
	int		j;
	char	*str;

	i = 0;

	while (left_str[i] && left_str[i] != '\n')
		i++;

	if (!left_str[i] || !left_str)
	{
		free(left_str);
		return (NULL);
	}

	str = (char *)malloc(sizeof(char) * (ft_strlen(left_str) - i + 1));

	if (!str)
		return (NULL);

	i++;
	j = 0;

	while (left_str[i])
		str[j++] = left_str[i++];

	str[j] = '\0';

	free(left_str);
	return (str);
}

int main() {
    char *str = "Hello, world!";
	char *left_str_0 = "This is a test\nline\nwith multiple\nlines.";
	char *left_str_1 = malloc(sizeof(char) * 6);  
	left_str_1[0] = 'H';
	left_str_1[1] = 'e';
	left_str_1[2] = 'l';
	left_str_1[3] = 'l';
	left_str_1[4] = 'o';
	left_str_1[5] = '\0';
	char *buff = " world!";
	
    printf("Testando ft_strchr:\n");
    printf("Caractere 'o' encontrado em: %s\n", ft_strchr(str, 'o'));
    printf("Caractere 'z' encontrado em: %s\n", ft_strchr(str, 'z'));

	printf("\nTestando ft_strjoin:\n");
	char *joined_str = ft_strjoin(left_str_1, buff);
	if (joined_str != NULL) {
		printf("String concatenada: %s\n", joined_str);
		free(joined_str);  // Não esqueça de liberar a memória alocada para joined_str
	}

    printf("\nTestando ft_get_line:\n");
    char *line = ft_get_line(left_str_0);
    if (line != NULL) {
        printf("Linha obtida: %s\n", line);
        free(line);
    }

    printf("Testando ft_new_left_str:\n");
    char *new_left_str = ft_new_left_str(left_str_0);
    if (new_left_str != NULL) {
        printf("Nova string após a primeira linha: %s\n", new_left_str);
        free(new_left_str);
    }

    return 0;
}