/* Exercise 4-3. Given the basic framework, it's straightforward to extend
  the calculator. Add the modulus (%) operator and provisions for negative
  numbers. */

/* Exercise 4-4. Add commands to print the top element of the stack without
  popping, to duplicate it, and to swap the top two elements. Add a command
  to clear the stack. */

/* Exercise 4-5. Add access to library functions like sin, exp, and pow.
  See <math.h> in Appendix B */

/* Exercise 4-6. Add commands for handling variables. (It's easy to provide
  twenty-six variables with single-letter names.) Add a variable for the
  most recently printed value. */

/* Exercise 4-7. Write a routine ungets(s) that will push back an entire
  string onto the input. Should ungets know about buf and bufp, or should it
  just use ungetch? */

/* Exercise 4-8. Suppose there will never be more than one character of
  pushback. Modify getch and ungetch accordingly. */

#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h> /* for sin(), exp(), pow() */

#define MAXOF 100   /* max size of operand or operator */
#define NUMBER '0'  /* signal that a number was found */

int getop(char []);
void push(double);
void peek(void);
double pop(void);
void swap(void);
void duplicate(double copy[]);
void clear(void);

/* reverse Polish calculator */
int main()
{
  int type, var;
  double op2, v;
  char s[MAXOF];
  double variable[26];

  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case '=':
      pop();
      if (var >= 'A' && var <= 'Z')
        variable[var-'A'] = pop();
      else
        printf("error: no variable name\n");
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0)
        push(pop() / op2);
      else
        printf("error: zero divisor\n");
      break;
    case '%':
      op2 = pop();
      push((int)pop() % (int)op2);
      break;
    case '^':
      op2 = pop();
      push(pow(pop(), op2));
      break;
    case 's':
      push(sin(pop()));
      break;
    case 'e':
      push(exp(pop()));
      break;
    case '\n':
      v = pop();
      printf("\t%.8g\n", v);
      break;
    default:
      if (type >= 'A' && type <= 'Z')
        push(variable[type-'A']);
      else if (type == 'v')
        push(v);
      else
        printf("error: unknown command %s\n", s);
      break;
    }
    var = type;
  }
  return 0;
}

#define MAXVAL 100  /* maximum depth of val stack */

int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f)
{
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}

/* peek: print top value from the stack without popping */
void peek(void)
{
  if (sp > 0)
    printf("%f\n", val[sp-1]);
  else {
    printf("error: stack empty\n");
  }
}

/* pop: pop and return top value from stack */
double pop(void)
{
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

/* swap: swap top two elements of stack */
void swap(void)
{
  double temp;
  if (sp > 1) {
    temp = val[sp-2];
    val[sp-2] = val[sp-1];
    val[sp-1] = temp;
  } else {
    printf("error: stack does not have two elements to swap\n");
  }
}

/* duplicate: duplicate the stack */
void duplicate(double copy[])
{ 
  int i;
  for (i = 0; i < sp; i++)
    copy[i] = val[i];
}

/* clear: clear the stack */
void clear(void)
{
  sp = 0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
  int i, c;

  while((s[0] = c = getch()) == ' ' ||  c == '\t')
    ;
  s[1] = '\0';
  if (!isdigit(c) && c != '.' && c != '-')
    return c; /* not a number */
  i = 0;
  if (isdigit(c) || c == '-') /* collect integer part */
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.') /* collect fraction part */
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  if (c != EOF)
    ungetch(c);
  return (i == 1 && s[0] == '-') ? '-' : NUMBER;
}

void ungets(char s[])
{
  int i;
  for (i = 0; s[i] != '\0'; i++)
    ;
  for (i--; i >= 0; i--)
    ungetch(s[i]);
}

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;      /* next free position in buf */

int getch(void) /* get a (possibly pushed back) character */
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}