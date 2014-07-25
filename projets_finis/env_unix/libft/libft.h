/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 12:06:55 by rnicolas          #+#    #+#             */
/*   Updated: 2014/04/16 15:24:38 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 512
# define DELIM_CHAR '\n'

typedef struct		s_read
{
	int				size;
	int				index;
	int				fd;
	char			*read;
	struct s_read	*next;
}					t_read;

typedef struct		s_buff
{
	int				fd;
	ssize_t			size;
	ssize_t			i;
	char			buff[BUFF_SIZE];
	struct s_buff	*next;
}					t_buff;

void				*ft_memccpy(void *s1, const void *s2, int c, size_t n);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strstr(const char *str1, const char *str2);
void				ft_bzero(void *str, size_t size);
int					ft_atoi(const char *str);
void				*ft_memchr(const void *str, int c, size_t n);
int					ft_strcmp(const char *str1, const char *str2);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_isalnum(int n);
int					ft_isalpha(int n);
int					ft_isascii(int n);
int					ft_isdigit(int n);
int					ft_isprint(int n);
int					ft_memcmp(const void *str1, const void *str2, size_t n);
void				*ft_memcpy(void *dest, void const *src, size_t size);
void				*ft_memmove(void *s1, const void *s2, size_t n);
void				*ft_memset(void *str, int c, size_t n);
char				*ft_strcat(char *str1, const char *str2);
char				*ft_strcpy(char *str1, const char *str2);
char				*ft_strdup(const char *str1);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *str);
char				*ft_strncat(char *str1, const char *str2, size_t n);
int					ft_strncmp(const char *str1, const char *str2, size_t n);
char				*ft_strncpy(char *str1, const char *str2, size_t n);
char				*ft_strnstr(const char *str1, const char *str2, size_t n);
char				*ft_strrchr(const char *str, int c);
char				*ft_strstr(const char *str1, const char *str2);
int					ft_tolower(int n);
int					ft_toupper(int n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_strchr(const char *str, int c);
void				ft_strdel(char **ap);
int					get_next_line(int fd, char **line);
void				free_table(char **table);
size_t				table_len(char **table);
int					ft_strisnum(char *str);
char				*ft_append(char *str, char c);

#endif
