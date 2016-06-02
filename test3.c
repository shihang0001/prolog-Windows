#include <SWI-Prolog.h>
#include <stdio.h>


typedef int BOOL;

fid_t fid;

void consult()
{
	term_t goal3=PL_new_term_ref();
	functor_t s3 = PL_new_functor(PL_new_atom("consult"),1);
	term_t a3=PL_new_term_ref();
	
	PL_put_atom_chars(a3, "D:\\extern\\niconico.pl");
	PL_cons_functor(goal3,s3,a3);
	PL_call(goal3,NULL);
}


void setup()
{
	int r;
	int argc=1;
	char *argv[20];
	argv[0]="prolog.c";
	PL_initialise(argc,argv);
	fid=PL_open_foreign_frame();
}

void clear()
{
	PL_discard_foreign_frame(fid);
	PL_halt(1);
}

void run()
{
	fid_t fid;
	char *goal;
	term_t g = PL_new_term_ref();
	int aaa;
	
	goal="nico(333)";
	PL_chars_to_term(goal, g);
	aaa=PL_call(g, NULL);
	
	printf("\nresult: %d\n",aaa);	
}


int main(int argc,char *argv[])
{
	
	setup();
	consult();
	run();
	clear();
	
	printf("test");
	return 0;
}
