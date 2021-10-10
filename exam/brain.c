
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
    int count;
    
    count = 0;
    while(*s){
        if(*s == '[')
            count++;
        else if(*s == ']'){
            if(count == 1)
                break;
            else
                count--;
        }
        s++;
    }
    return s;
    
}
#include<unistd.h>
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
		else if (c == '.'){
			printf("%c", str[g_index]);
		}
		else if (c == '[')
		{
			while(str[g_index] != 0)
			    interpter(instr + 1);
			instr = gotoNextBracket(instr);
		}
		else if (c ==']')
		{
		    return ;
		}

		instr++;
	}
    
}


int main(int ac, char **av) {
	ac  = 1;
	reset();
	g_index = 0;
	char *s = "+++++[>++++[>++++H>+++++i<<-]>>>++\n<<<<-]>>--------.>+++++.>.";
	interpter(s);
}
