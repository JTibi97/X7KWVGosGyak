#include <signal.h>
#include "hdr.h"

static void sig_usr1(int);     
static void sig_intr(int); 
static void sig_quit(int);
static void sig_alarm(int);

int main(void)
{
  /*if (signal(SIGALRM, sig_alarm) == SIG_ERR)
    err_sys("hiba: signal(SIGALRM, ...)");
  if (signal(SIGUSR1, sig_usr1) == SIG_ERR)
    err_sys("hiba: signal(SIGUSR1, ...)");
  if (signal(SIGINT, sig_intr) == SIG_ERR)
    err_sys("hiba: signal(SIGINT, ...)");
  if (signal(SIGQUIT, sig_quit) == SIG_ERR)
    err_sys("hiba: signal(SIGQUIT, ...)");
  for ever pause();*/
}

static void sig_alarm(int sig)
{
  printf("SIGALRM jelet vettem...\n");
  return;
}

static void sig_quit(int sig)
{
  printf("SIGQUIT jelet vettem...\n");
/*  if (signal(SIGQUIT, SIG_DFL) == SIG_ERR)
    err_sys("nem lehet visszaallitani ezt a jelet...");*/
  return;
}

static void sig_intr(int sig)
{
  printf("SIGINT jelet vettem...\n");
 /* if (signal(SIGINT, sig_intr) == SIG_ERR)
    err_sys("nem lehet ujra betolteni...");*/
  return;
}

static void sig_usr1(int sig)
{
  printf("SIGUSR1 jelet vettem...\n");
  alarm(1);
  printf("a riasztas 1 masodperc mulva elindul!\n");
  return;
}
