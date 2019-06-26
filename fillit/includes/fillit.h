#ifndef FILLIT_H
# define FILLIT_H

/*
# define BUFF_SIZE 21
# define ZL "FGFHKHAAA"
# define ZU "GDGFFHGAA"
# define ZR "HFDFGHKAA"
# define ZD "IFGGGHFAA"
# define D "JEHFFFFFA"
# define RU "KGFHLIAAA"
# define RR "LFGGHFFAA"
# define RD "MCFFFLAAA"
# define RL "NFGGGGHAA"
# define H "OHEITAAAA"
# define TU "PFDFGGLAA"
# define TL "QFGGGHGAA"
# define TD "RGFHLGAAA"
# define TR "SDGFFHFAA"
# define S "TFFGHHAAA"
# define LU "UGFHILAAA"
# define LR "VFGGHGGAA"
# define LD "WGFHLFAAA"
# define LL "XDGFFFHAA"
# define NA "YAAAAAAAA"
# define ER "EAAAAAAAA"
# define ERROR -1

# include "libft.h"
*/


# define BUFF_SIZE 21
# define ZL "FQKEEE"
# define ZU "GIQMEE"
# define ZR "HKQEEE"
# define ZD "IMQIEE"
# define D "JMMMME"
# define RU "KSMEEE"
# define RR "LQIIEE"
# define RD "MGSEEE"
# define RL "NMMQEE"
# define H "OTEEEE"
# define TU "PISEEE"
# define TL "QMQMEE"
# define TD "RSIEEE"
# define TR "SIQIEE"
# define S "TQQEEE"
# define LU "UMSEEE"
# define LR "VQMMEE"
# define LD "WSGEEE"
# define LL "XIIQEE"
# define NA "YEEEEE"
# define ER "EEEEEE"
# define ERROR -1

# include "libft.h"
# include <stdint.h>


typedef struct s_p 	t_p;
struct				s_p
{
	unsigned int	name[6];
	unsigned int	pos; /* value is pos of the block in board eventually*/
	__uint128_t		value;
	unsigned int 	height;
};

int		read_blocks(int fd, t_p *lstp);
int		tetri_offset(int *arr, t_p *lstpj);
int		define_blocks(char *o_arr, t_p *lstpj);
int		ft_lsqrt(int nb);
int		issafe(int i, int *name, int w);
void	gen_arr(int *arr);
void	gen_board(__uint128_t *board, int w);
int		place_piece(int i, t_p *lstpj, __uint128_t *board, int w);
void	unplace_piece(int i, t_p *lstpj, __uint128_t *board, int w);
void	print_board(t_p*lstp, int boardsize);
int		solveboard(t_p *lstpj, __uint128_t *board, int *arr, int boardsize, t_p *lstp);





#endif
