#include "push_swap.h"

int      len_word(char const *s, char c, int i)
{
        int     lengthofword;

        lengthofword = 0;
        while (s[i] != c && s[i++])
                lengthofword++;
        return (lengthofword);
}

char    **ft_split(char const *s, char c)
{
        int             i;
        int             wordcount;
        char            **words;
        int             lenofword;
        int             j;

        i = 0;
        j = -1;
        wordcount =  lenght_words(s, c);
        words = (char **)malloc((wordcount + 1) * sizeof(char *));
        if (!words)
                return (NULL);
        while (++j < wordcount)
        {
                while (s[i] == c)
                        i++;
                lenofword = len_word(s, c, i);
                words[j] = ft_substr(s, i, lenofword);
                i += lenofword;
        }
        words[j] = 0;
        return (words);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (start >= size)
		start = size;
	if (len > size - start)
		len = size - start;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s[start], len + 1);
	return (str);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (size == 0)
		return (len);
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (i < size)
		dst[i] = '\0';
	return (len);
}

void    free_err(t_src *src, char *str)
{
        int i;

        i = 0;
        if(str)
        {
                while(str[i])
                        write(1, &str[i++], 1);
        }
	free_all(src);
        exit(1);
}
