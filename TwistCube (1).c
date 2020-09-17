#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

char F[2][2] = {
  {'B', 'B'},
  {'B', 'B'}
};
char L[2][2] = {
  {'R', 'R'},
  {'R', 'R'}
};
char U[2][2] = {
  {'W', 'W'},
  {'W', 'W'}
};
char B[2][2] = {
  {'G', 'G'},
  {'G', 'G'}
};
char D[2][2] = {
  {'Y', 'Y'},
  {'Y', 'Y'}
};
char R[2][2] = {
  {'O', 'O'},
  {'O', 'O'}
};

int i,j;

void clockwise(char a[2][2])
{
char y = a[1][0];
a[1][0] = a[1][1];
a[1][1] = a[0][1];
a[0][1] = a[0][0];
a[0][0] = y;
}

void counter(char b[2][2])
{
char y = b[1][0];
b[1][0] = b[0][0];
b[0][0] = b[0][1];
b[0][1] = b[1][1];
b[1][1] = y;
}

void Forward(bool reverse)
{
char u1,u2,r1,r2;
    if(reverse)
	{
u1 = U[0][1];
u2 = U[1][1];
/*R moves to U*/
	U[1][1] = R[0][0];
	U[0][1] = R[1][0];
/*D moves to R*/
	R[0][0] = D[1][1];
	R[1][0] = D[0][1];
/*L moves to D*/
	D[0][1] = L[0][1];
	D[1][1] = L[1][1];
/*U moves to L*/
	L[0][1] = u1;
	L[1][1] = u2;
/*Second column of F becomes first row of F*/
	counter(F);
		}
	else{
r1 = R[0][0];
r2 = R[1][0];
/*U moves to R*/
	R[0][0] = U[1][1];
	R[1][0] = U[0][1];
/*L moves to U*/
	U[0][1] = L[0][1];
	U[1][1] = L[1][1];
/*D moves to L*/
	L[0][1] = D[0][1];
	L[1][1] = D[1][1];
/*R moves to D*/
	D[0][1] = r2;
	D[1][1] = r1;
/*First column of F becomes first row of F*/
	clockwise(F);
	}
}

void Left(bool reverse)
{
char u1,u2,r1,r2;
    if(reverse)
	{
u1 = U[1][0];
u2 = U[1][1];
/*F moves to U*/
	U[1][1] = F[1][0];
	U[1][0] = F[0][0];
/*D moves to F*/
	F[1][0] = D[0][0];
	F[0][0] = D[0][1];
/*B moves to D*/
	D[0][0] = B[0][1];
	D[0][1] = B[1][1];
/*U moves to B*/
	B[1][1] = u1;
	B[0][1] = u2;
/*Second column of L becomes first row of L*/
	counter(L);
		}
	else{
r1 = F[0][0];
r2 = F[1][0];
/*U moves to F*/
	F[0][0] = U[1][0];
	F[1][0] = U[1][1];
/*B moves to U*/
	U[1][0] = B[1][1];
	U[1][1] = B[0][1];
/*D moves to B*/
	B[0][1] = D[0][0];
	B[1][1] = D[0][1];
/*F moves to D*/
	D[0][0] = r2;
	D[0][1] = r1;
/*First column of L becomes first row of L*/
	clockwise(L);
	}
}

void Up(bool reverse)
{
char l[2][2];
l[0][0] = L[0][0];
l[0][1] = L[0][1];
l[1][0] = L[1][0];
l[1][1] = L[1][1];
    if(!reverse)
	{
	for (i = 0; i< 2; i++)
	{
		L[0][i] = F[0][i];
		F[0][i] = R[0][i];
		R[0][i] = B[0][i];
		B[0][i] = l[0][i];
	}
/*Second column of U becomes first row of U*/
	clockwise(U);
		}
	else{
	for (i = 0; i < 2; i++)
	{
		L[0][i] = B[0][i];
		B[0][i] = R[0][i];
		R[0][i] = F[0][i];
		F[0][i] = l[0][i];
	}
/*First column of U becomes first row of U*/
	counter(U);
	}
}

void Back(bool reverse)
{
char u1,u2,r1,r2;
    if(reverse)
	{
u1 = U[0][0];
u2 = U[1][0];
/*L moves to U*/
	U[0][0] = L[0][0];
	U[1][0] = L[1][0];
/*D moves to L*/
	L[0][0] = D[0][0];
	L[1][0] = D[1][0];
/*R moves to D*/
	D[1][0] = R[0][1];
	D[0][0] = R[1][1];
/*U moves to R*/
	R[1][1] = u1;
	R[0][1] = u2;
/*Second column of B becomes first row of B*/
	counter(B);
		}
	else{
r1 = R[0][1];
r2 = R[1][1];
/*D moves to R*/
	R[0][1] = D[1][0];
	R[1][1] = D[0][0];
/*L moves to D*/
	D[0][0] = L[0][0];
	D[1][0] = L[1][0];
/*U moves to L*/
	L[0][0] = U[0][0];
	L[1][0] = U[1][0];
/*R moves to U*/
	U[0][0] = r2;
	U[1][0] = r1;
/*First column of B becomes first row of B*/
	clockwise(B);
	}
}

void Right(bool reverse)
{
char u1,u2,r1,r2;
    if(!reverse)
	{
u1 = U[0][0];
u2 = U[0][1];
/*F moves to U*/
	U[0][0] = F[0][1];
	U[0][1] = F[1][1];
/*D moves to F*/
	F[0][1] = D[1][1];
	F[1][1] = D[1][0];
/*B moves to D*/
	D[1][0] = B[0][0];
	D[1][1] = B[1][0];
/*U moves to B*/
	B[0][0] = u2;
	B[1][0] = u1;
/*Second column of R becomes first row of R*/
	clockwise(R);
		}
	else{
r1 = F[0][1];
r2 = F[1][1];
/*U moves to F*/
	F[0][1] = U[0][0];
	F[1][1] = U[0][1];
/*B moves to U*/
	U[0][0] = B[1][0];
	U[0][1] = B[0][0];
/*D moves to B*/
	B[0][0] = D[1][0];
	B[1][0] = D[1][1];
/*F moves to D*/
	D[1][0] = r2;
	D[1][1] = r1;
/*First column of R becomes first row of R*/
	counter(R);
	}
}

void Down(bool reverse)
{
char l[2][2];
l[0][0] = L[0][0];
l[0][1] = L[0][1];
l[1][0] = L[1][0];
l[1][1] = L[1][1];
    if(reverse)
	{
	for (i = 0; i< 2; i++)
	{
		L[1][i] = F[1][i];
		F[1][i] = R[1][i];
		R[1][i] = B[1][i];
		B[1][i] = l[1][i];
	}
/*Second column of U becomes first row of U*/
	counter(D);
		}
	else{
	for (i = 0; i < 2; i++)
	{
		L[1][i] = B[1][i];
		B[1][i] = R[1][i];
		R[1][i] = F[1][i];
		F[1][i] = l[1][i];
	}
/*First column of U becomes first row of U*/
	clockwise(D);
	}
}

void X(bool reverse)
{
char b[2][2];
char f[2][2];
b[0][0] = B[0][0];
b[0][1] = B[0][1];
b[1][0] = B[1][0];
b[1][1] = B[1][1];
f[0][0] = F[0][0];
f[0][1] = F[0][1];
f[1][0] = F[1][0];
f[1][1] = F[1][1];
if(!reverse)
{
F[0][0] = D[0][1];
F[0][1] = D[1][1];
F[1][0] = D[0][0];
F[1][1] = D[1][0];
D[0][0] = b[0][1];
D[0][1] = b[1][1];
D[1][0] = b[0][0];
D[1][1] = b[1][0];
B[0][0] = U[0][1];
B[0][1] = U[1][1];
B[1][0] = U[0][0];
B[1][1] = U[1][0];
U[0][0] = f[0][1];
U[0][1] = f[1][1];
U[1][0] = f[0][0];
U[1][1] = f[1][0];
counter(L);
clockwise(R);
}
else
{
F[0][0] = U[1][0];
F[0][1] = U[0][0];
F[1][0] = U[1][1];
F[1][1] = U[0][1];
U[0][0] = b[1][0];
U[0][1] = b[0][0];
U[1][0] = b[1][1];
U[1][1] = b[0][1];
B[0][0] = D[1][0];
B[0][1] = D[0][0];
B[1][0] = D[1][1];
B[1][1] = D[0][1];
D[0][0] = f[1][0];
D[0][1] = f[0][0];
D[1][0] = f[1][1];
D[1][1] = f[0][1];
clockwise(L);
counter(R);
}
}

void Y(bool reverse)
{
char l[2][2];
l[0][0] = L[0][0];
l[0][1] = L[0][1];
l[1][0] = L[1][0];
l[1][1] = L[1][1];
if(!reverse)
{
for (i = 0; i < 2; i++)
{
	for (j = 0; j < 2; j++)
	{
		L[i][j] = F[i][j];
		F[i][j] = R[i][j];
		R[i][j] = B[i][j];
		B[i][j] = l[i][j];
	}
}
clockwise(U);
clockwise(D);
}
else
{
for (i = 0; i < 2; i++)
{
	for (j = 0; j < 2; j++)
	{
		L[i][j] = B[i][j];
		B[i][j] = R[i][j];
		R[i][j] = F[i][j];
		F[i][j] = l[i][j];
	}
}
counter(U);
counter(D);
}
}

void Z(bool reverse)
{
char u[2][2];
char d[2][2];
u[0][0] = U[0][0];
u[0][1] = U[0][1];
u[1][0] = U[1][0];
u[1][1] = U[1][1];
d[0][0] = D[0][0];
d[0][1] = D[0][1];
d[1][0] = D[1][0];
d[1][1] = D[1][1];
if(!reverse)
{

for (i = 0; i < 2; i++)
{
	for (j = 0; j < 2; j++)
	{
		U[i][j] = L[i][j];
		L[i][j] = d[i][j];
	}
}
D[0][0] = R[1][1];
D[0][1] = R[1][0];
D[1][0] = R[0][1];
D[1][1] = R[0][0];
R[0][0] = u[1][1];
R[0][1] = u[1][0];
R[1][0] = u[0][1];
R[1][1] = u[0][0];
clockwise(F);
counter(B);
}
else
{
for (i = 0; i < 2; i++)
{
	for (j = 0; j < 2; j++)
	{
		D[i][j] = L[i][j];
		L[i][j] = u[i][j];
	}
}
U[0][0] = R[1][1];
U[0][1] = R[1][0];
U[1][0] = R[0][1];
U[1][1] = R[0][0];
R[0][0] = d[1][1];
R[0][1] = d[1][0];
R[1][0] = d[0][1];
R[1][1] = d[0][0];
counter(F);
clockwise(B);
}
}

void Display()
{
printf("   +------+");
printf("\n  / %c  %c /|", U[0][0], U[0][1]);
printf("\n / %c  %c /%c|", U[1][0], U[1][1], F[0][1]);
printf("\n+------+%c |", F[0][0]);
printf("\n| %c  %c | %c|", L[0][0], L[0][1], F[1][1]);
printf("\n|      |%c +", F[1][0]);
printf("\n| %c  %c | /", L[1][0], L[1][1]);
printf("\n+------+\n");
}

int main(int argc, char* message[])
{
char enter;
int i = 0;
char front;
char left;
char up;
(void)argc;
	while(message[1][i] != '\0')
	{
		if (message[1][i] == '+')
		{
			enter = tolower(message[1][i-1]);
		}
		else if(message[1][i] == '2')
		{
			enter = message[1][i-1];
		}
		else
		{
			enter = message[1][i];
		}
		switch (enter)
	{
		case 'F':
			Forward(false);
			break;
		case 'f':
			Forward(true);
			Forward(true);
			break;
		case 'B':
			Back(false);
			break;
		case 'b':
			Back(true);
			Back(true);
			break;
		case 'L':
			Left(false);
			break;
		case 'l':
			Left(true);
			Left(true);
			break;
		case 'R':
			Right(false);
			break;
		case 'r':
			Right(true);
			Right(true);
			break;
		case 'U':
			Up(false);
			break;
		case 'u':
			Up(true);
			Up(true);
			break;
		case 'D':
			Down(false);
			break;
		case 'd':
			Down(true);
			Down(true);
			break;
		case 'Y':
			Y(false);
			break;
		case 'y':
			Y(true);
			Y(true);
			break;
		case 'X':
			X(false);
			break;
		case 'x':
			X(true);
			X(true);
			break;
		case 'Z':
			Z(false);
			break;
		case 'z':
			Z(true);
			Z(true);
			break;
		default:
			Display();
			break;
	}
	i++;	
}
Display();
printf("Back: %c %c %c %c\n", B[0][0], B[0][1], B[1][0], B[1][1]);
printf("Down: %c %c %c %c\n", D[0][0], D[0][1], D[1][0], D[1][1]);
printf("Right: %c %c %c %c\n", R[0][0], R[0][1], R[1][0], R[1][1]);
front = F[0][0];
left = L[0][0];
up = U[0][0];
if(up == U[0][1] && up == U[1][0] && up == U[1][1])
{
	if(left == L[0][1] && left == L[1][0] && left == L[1][1])
{
		if(front == F[0][1] && front == F[1][0] && front == F[1][1])
{
			printf("Hurrah!\n");
}
}
}
	return 0;
}
