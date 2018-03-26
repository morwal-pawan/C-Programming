#define MAX 20
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
typedef struct stack{
	int stk[MAX];
	int top;
}stack;
int is_empty(stack *s);
int is_full(stack *s);
void push(stack *s,int val);
int pop(stack *s);
int peep(stack *s);
int is_operand(char op);
int is_operator(char op);
int prec(char op);
void intopre(char *in,char *pre);
void intopost(char *in,char *post);
main(){
	char in[25],pre[25],post[25];
	printf("enter in\n");
	scanf("%s",in);
	intopost(in,post);
	intopre(in,pre);
	puts(pre);
	puts(post);
}

int is_empty(stack *s){
	if(0==(s->top)){
		return 1;
	}
	else
		return 0;
}
int is_full(stack *s){
	if(MAX==(s->top)){
		printf("\nstack overflow\n");
		return 1;
	}
	else
		return 0;
}
void push(stack *s,int val){
	int r;
	r=is_full(s);
	if(1==r)
		exit(0);
	else
		s->stk[s->top]=val;
		s->top++;
}
int pop(stack *s){
	int r,val;
	r=is_empty(s);
	if(1==r){
		printf("stack underflow\n");
		exit(0);
	}
	else{
		s->top--;
		val=s->stk[s->top];
		return(val);
	}
}

int peep(stack *s){
	int r,val;
	r=is_empty(s);
	if(1==r){
		printf("stack underflow\n");
		exit(0);
	}
	else{
		val=s->stk[s->top-1];
		return(val);
	}
}

int is_operand(char op){
	if(isalpha(op))
		return 1;
	else
		return 0;
}

int is_operator(char op){
	if(op=='+'||op=='-'||op=='*'||op=='/'||op=='%')
		return 1;
	else
		return 0;
}

int prec(char op){
	if(op=='^' || op=='$')
		return 4;
	if(op=='*' || op=='/' || op=='%')
		return 3;
	else if(op=='+' || op=='-')
		return 2;
	else
		return 1;
}

void intopost(char *in,char *post){

	char op;
	int i,j=0;
	stack s;
	s.top=0;
	strcat(in,")");
	push(&s,'(');
	for(i=0; in[i]!='\0'; i++){
		if(in[i]=='(')
			push(&s,'(');
		else if(is_operand(in[i])){
			post[j]=in[i];
			j++;
		}
		else if(is_operator(in[i])){
			while(1){
                op=peep(&s);
				if(prec(op)>=prec(in[i])){
				   post[j]=pop(&s);
				   j++;
				}
				else{
					break;
				}
			}
			push(&s,in[i]);
		}
		else if(in[i]==')'){
			while((op=pop(&s))!='('){
				post[j]=op;
				j++;
			}
		}

	}
	post[j]='\0';
	if(! is_empty){
		printf("wrong inpur\n");
		exit(0);
	}
}
void intopre(char *in,char *pre){
	char op,res[30];
	int i,j=0;

	stack s;
	s.top=0;
	strcat(in,")");
	res[0]='(';
	strcat(res,in);
	strcpy(in,res);
	res[0]='\0';
	j=0;

	for(i=strlen(in)-1; i>=0 ; i--){

		if( in[i] == ')' )
			push(&s,')');

		else if( is_operand(in[i]) ){
			res[j]=in[i];
			j++;
		}
		else if(is_operator(in[i])){
			while(1){
				op=peep(&s);
				if( prec(op)>prec(in[i]) ){
				   res[j]=pop(&s);
				   j++;
				}
				else
					break;
			}
			push(&s,in[i]);
		}
		else if( in[i]=='(' ){
			while((op=pop(&s))!=')'){
				res[j]=op;
				j++;
			}
		}

	}
	res[j]='\0';
	i=0;
	for(j=strlen(res)-1;j>=0;j--){
		pre[i]=res[j];
		i++;
	}
	pre[i]='\0';
	if(! is_empty){
		printf("wrong inpur\n");
		exit(0);
	}
}
