
#include<stdio.h>

char str[2048];
int g_index;

void reset(){
	int i;

	i = 0;
	while (i < 2048)
		str[i++] = 0;

}


char *gotoNextBracket(char *s)
{
    
    while(*s != ']')
        s++;
    return s;
    
}



void interpter(char *instr)
{
	char c;
	
	while(*instr){
		c = *instr;
		if (c  == '>')
			g_index++;
		else if (c == '<')
			g_index--;
		else if (c == '+')
			str[g_index]++;
		else if (c == '-')
			str[g_index]--;
		else if (c == '.')
			printf("%x", str[g_index]);
		else if (c == '[')
		{
			if(str[g_index] != 0){
			    continue;
			}
		}
		else if (c ==']')
		{
		    if (str[g_index]){
		        while(*instr != '[')
		            instr--;
		    }
		}

		instr++;
	}
}


int main() {
	reset();
	g_index = 0;
	char s[] = "+++++[>++++[>+++H>+++++i<<-]>>>++\n<<<<-]>>--------.>+++++.>.";
	
	
	interpter(s);
}

