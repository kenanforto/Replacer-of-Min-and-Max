#include <stdio.h>

char* zamijeni_min_max(char *u)
{
	char *p=u;
	char *h=u;
	char *t=u;
	char *a=u;
	char *b=u;
	char *c=u;
	char *d=u;
	char *e=u;
	char *f=u;
	int g,sum=0,sum1;
	while(*h!='\0')//WHILE KOJI TRAZI PRVU NAJVECU RIJEC U STRINGU
	{
		if(!(*h==' ' || *h=='\0' || *h=='.' || *h==',' || *h=='!' || *h=='?' || *h==';'))
		{
			e=h;
			while(!(*h==' ' || *h=='\0' || *h=='.' || *h==',' || *h=='!' || *h=='?' || *h==';'))
			{
				f=h;
				if(*h=='\0')
				{
					break;
				}
				h++;
			}
			g=f-e+1;
			if(g>sum)//POSTAVLJANJE POKAZIVACA NA POCETAK I KRAJ TE NAJVECE RIJECI
			{
				sum=g;//BROJ SLOVA NAJVECE RIJECI
				a=e;
				b=f;
			}
		}
		if(*h=='\0')
		{
		break;
		}
		h++;
	}
	sum1=sum;
	while(*t!='\0')//WHILE ZA PRONALAZAK NAJMANJE RIJECI////////
	{
		if(!(*t==' ' || *t=='\0' || *t=='.' || *t==',' || *t=='!' || *t=='?' || *t==';'))
		{
			e=t;
			while(!(*t==' ' || *t=='\0' || *t=='.' || *t==',' || *t=='!' || *t=='?' || *t==';'))
			{
				f=t;
				if(*t=='\0')
				{
					break;
				}
				t++;
			}
			g=f-e+1;
			if(sum>g && g<sum1)//POSTAVLJA POKAZIVAC NA POCETAK  I KRAJ NAJMANJE RIJEC 
			{
				c=e;
				d=f;
				sum1=g;//BROJ SLOVA NAJMANJE RIJECI
				
			}
		}
		if(*t=='\0')
		{
			break;
		}
		t++;
		//else break;
	}
	int sum2=sum1;
	char temp;
	if(sum==sum1)
	return p;
	if(b>c)//AKO SE MAKSIMALNA RIJEC 
	{
	while(sum1!=0)//PREBACUJE MANJU RIJEC NA VECU I DIO VECE NA MANJU 
	{
		temp=*d;
		*d=*b;
		*b=temp;
		sum1--;
		d--;
		b--;
	}
	while((sum-sum2)>0)//PREOSTALI DIO VECE RIJECI PREBACUJE NA ODGOVARAJUCE MJESTO POSLIJE POKAZIVACA NA KRAJ MANJE RIJECI
	{
		u=p;
		temp=*a;
		while(u!=a)
		u++;
		while(u!=c)
		{
			*u=*(u-1);//PRESLAZE STRING TAKO DA OMJERA ZA JEDNOS MJESTO CITAV STRING DOK NE DODJE DO POKAZIVACA C KOJI JE POKAZIVAO NA POCETAK MANJE RIJECI
			u--;
		}
		*c=temp;
		sum--;
		c++;
		a++;
	}
	}
	else if(c>b)//ISTO RADIO KAO KAD JE MAX IZA MANJE RIJECI SAMO STO JE U OVOM SLUCAJU MAX ISPRED MANJE RIJECI 
	{
		while(sum1!=0)
		{
			temp=*c;
			*c=*a;
			*a=temp;
			sum1--;
			a++;
			c++;
		}
	while((sum-sum2)>0)//ZATO STO SMO VEC POMJERILI DIO NAJVECE RIJECI PREOSTALI DIO RIJECI POMJERAMO DO VRIJEDNOSTI KADA ODUZMEMO OD BROJA SLOVA NAJVECE RIJECI BROJ SLOVA MIN RIJECI I KADA POMJERIMO ZA JEDNO SLOVO ODUZMEM 1
	{
		u=p;
		temp=*b;
		while(u!=b)
		u++;
		while(u!=d)
		{
			*u=*(u+1);
			u++;
		}
		*d=temp;
		sum--;
		b--;
		d--;
	}
	}

	return p;
}
int main() {
	char n[]="Ovo rec.enica1 recenica.ca2 6 proba.";
	printf("%s",zamijeni_min_max(n));
	return 0;
}