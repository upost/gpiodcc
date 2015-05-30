
#ifndef SRCP_H
#define SRCP_H

#define LISTENPORT 4303

/* Definition of a locomotive */
struct genericloco
{
	unsigned int address;
	unsigned int protocolversion;	/* 1 or 2 */
	unsigned int speedsteps;	/* 14/28/128 */
	unsigned int numfuncs;		/* Number of functions, 0-32 */
	unsigned int funcs;		/* 1 bit per function */
	unsigned int drivemode;		/* 0 = back, 1 = fwd, 2 = e-stop */
	unsigned int v;			/* Speed, as a fraction of vmax */
	unsigned int vmax;		/* Top speed */
	struct dccmessage *dccspeed;	/* Speed message */
	struct dccmessage *dccfunc0to4;	/* FL-F4 message */
	struct genericloco *next;	/* Linked list */
};

/* Definition of an accessory */
struct generic_accessory
{
	unsigned int address;
	unsigned int pairnr;
	unsigned int port;
	unsigned int value;
	struct dccmessage *dcccommand;
	struct generic_accessory *next;
};

extern void debug_printtrainlist(void);

/* Set up the listening socket for the server */
extern int setup_network(void);

extern int main(void);

#endif /* SRCP_H */
