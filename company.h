#ifndef COMPANY_H_INCLUDED
#define COMPANY_H_INCLUDED


typedef struct {
    int id;
    char description[20];
}sCompany;

int loadCompanyDescription(sCompany companies[], int size, int companyId, char description[]);
int showCompany(sCompany companies[], int size);
int validateCompanyId(sCompany companies[], int id, int size);



#endif // COMPANY_H_INCLUDED
