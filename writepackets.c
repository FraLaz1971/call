#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "packets.h"
int main(int argc, char **argv) {
   unsigned short int word[NMAX];
   unsigned short int hword[9];
   int npkt=atoi(argv[1]);
   char *fname=argv[2];
   int length=atoi(argv[3]);
   int i,j,k;
   unsigned char mybyte=255;
   // Open the binary file for writing
   FILE *wf = fopen(fname, "wb");

   // Check if file open successfully
   if (!wf) {
       printf("Cannot open file!\n");
       return 1;
   }

   // Initialize packet data
   struct Packet wpkt[npkt];
   struct DDSheader dhd[npkt];
   for (i=0;i<npkt;i++){
   dhd[i].sec_msb=0;
   dhd[i].sec_lsb=i+1;
   dhd[i].usec_msb=0;
   dhd[i].usec_lsb=1000*(i+1);
   dhd[i].gr_st_id=8;
   dhd[i].pkt_len=length+7;
   dhd[i].vc_id=1;
   dhd[i].lse_id=0;
   dhd[i].time_qual=0;
   dhd[i].time=(double)((dhd[i].sec_msb<<16)+dhd[i].sec_lsb)+\
   ((dhd[i].usec_msb<<16)+dhd[i].usec_lsb)/1000000.0;

   wpkt[i].ver = 0;
   wpkt[i].type = 0;
   wpkt[i].shf = 1;
   wpkt[i].apid = 1032;
   wpkt[i].sf = 0;
   wpkt[i].ssc = 100+i;
   wpkt[i].len = length;
   for(j=0;j<(length+1)/2;j++)
     wpkt[i].data[j]=65535-j;
   if(fmod(length+1,2)!=0.0)
     wpkt[i].lastbyte=mybyte;

   hword[0]=dhd[i].sec_msb;
   hword[1]=dhd[i].sec_lsb;
   hword[2]=dhd[i].usec_msb;
   hword[3]=dhd[i].usec_lsb;
   hword[4]=((dhd[i].pkt_len&5280)>>16);
   hword[5]=(dhd[i].pkt_len&255);
   hword[6]=dhd[i].gr_st_id;
   hword[7]=dhd[i].vc_id;
   hword[8]=(dhd[i].lse_id&255+dhd[i].time_qual);
   printf("%d+%d+%d+%d\n",wpkt[i].ver<<13,wpkt[i].type<<12,wpkt[i].shf<<11,wpkt[i].apid);
   word[0]=(wpkt[i].ver<<13)+(wpkt[i].type<<12)+(wpkt[i].shf<<11)+wpkt[i].apid;
   printf("%d+%d\n",wpkt[i].sf<<14,wpkt[i].ssc);
   word[1]=(wpkt[i].sf<<14)+wpkt[i].ssc;
   printf("%d\n",wpkt[i].len);
   word[2]=wpkt[i].len;
   for(j=0;j<(length+1)/2;j++)
     word[j+3]=wpkt[i].data[j];

   // Write pakets data to the file
  for(k=0;k<9;k++){
       swapword(&hword[k]);
       fwrite(&hword[k], 2, 1, wf);
  }
  for(k=0;k<(length+7)/2;k++){
       swapword(&word[k]);
       fwrite(&word[k], 2, 1, wf);
  }
   if(fmod(length+1,2)!=0.0){
       mybyte=wpkt[i].lastbyte;
       fwrite(&mybyte, 1, 1, wf);
   }
 }

   // Close the file after writing
   fclose(wf);


   // Display packets details
   for (i=0;i<npkt;i++){
       printf("seconds msb: %d\n", dhd[i].sec_msb);
       printf("seconds lsb: %d\n", dhd[i].sec_lsb);
       printf("useconds msb: %d\n", dhd[i].usec_msb);
       printf("useconds lsb: %d\n", dhd[i].usec_lsb);
       printf("packet length: %u\n", dhd[i].pkt_len);
       printf("ground station id: %hu\n", dhd[i].gr_st_id);
       printf("VC id: %d\n", dhd[i].vc_id);
       printf("lse id: %d\n", dhd[i].lse_id);
       printf("time quality: %d\n", dhd[i].time_qual);
       printf("time: %f\n", dhd[i].time);
       printf("pkt type: %d\n", wpkt[i].type);
       printf("sec. head. flag: %d\n", wpkt[i].shf);
       printf("apid: %d\n", wpkt[i].apid);
       printf("sequence flag: %d\n", wpkt[i].sf);
       printf("sequence counter: %d\n", wpkt[i].ssc);
       printf("pkt length: %d\n", wpkt[i].len);
       printf("\n");
   }

   return 0;
}
