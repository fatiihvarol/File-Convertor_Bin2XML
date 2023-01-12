#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

struct record {
 char name[64]; 
 char surname[32];  
 char gender; 
 char email[32];
 char phone_number[16];
 char address[32];
 char level_of_education[8];
 unsigned int income_level; 
 unsigned int expenditure; 
 char currency_unit[16];
 char currentMood[32];
 float height;
 unsigned int weight;
};


uint32_t converter(uint32_t val)
{
    uint32_t be = __builtin_bswap32(val);
    return be;
}

int main()
{
    FILE *dat, *XML;

    struct record *Employee;

    Employee = (struct record *)malloc(55*sizeof(struct record));

    dat = fopen("records.dat", "rb");
    int i;
    i=0;
    while (fread(&Employee[i], sizeof(struct record), 1, dat))
    {
        i++;
    }
    

    XML = fopen("Bin2XML.xml", "w"); 

    fprintf(XML, "<records>\n");
    
    for (int j = 1; j < 51; j++) 
    {
        

        fprintf(XML, "\t<row id= \"%d\">\n", j);
        fprintf(XML, "\t\t<%s>%s</%s>\n", "name", Employee[j].name,"name" );
        fprintf(XML, "\t\t<%s>%s</%s>\n", "surname", Employee[j].surname, "surname");
        fprintf(XML, "\t\t<%s>%c</%s>\n", "gender", Employee[j].gender, "gender");
        fprintf(XML, "\t\t<%s>%s</%s>\n", "email", Employee[j].email,"email" );
        fprintf(XML, "\t\t<%s>%s</%s>\n","phone_number", Employee[j].phone_number, "phone_number");
        fprintf(XML, "\t\t<%s>%s</%s>\n", "address", Employee[j].address, "address");
        fprintf(XML, "\t\t<%s>%s</%s>\n", "level_of_education", Employee[j].level_of_education, "level_of_education");
        fprintf(XML, "\t\t<%s '%u'>%u</%s>\n", "income_level",converter(Employee[j].income_level),Employee[j].income_level, "income_level");
        fprintf(XML, "\t\t<%s '%u'>%u</%s>\n", "expenditure",Employee[j].expenditure,converter(Employee[j].expenditure), "expenditure");
        fprintf(XML, "\t\t<%s>%s</%s>\n", "currency_unit", Employee[j].currency_unit, "currency_unit");
        fprintf(XML, "\t\t<%s>%s</%s>\n", "currentMood", Employee[j].currentMood,"currentMood");
        fprintf(XML, "\t\t<%s>%f</%s>\n", "height", Employee[j].height, "height");
        fprintf(XML, "\t\t<%s>%u</%s>\n", "weight", Employee[j].weight, "weight");
        fprintf(XML, "\t</row>\n");

    }
    fprintf(XML, "</records>\0");
    free(Employee);
    fclose(dat);
    fclose(XML);
    
}
