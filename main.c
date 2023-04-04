//eshehdula22
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read(int n, int id[], char name[][20], char surname[][20], char department[][20], int grades[]);
void sort(int id[], char name[][20], char surname[][20], char department[][20], int grades[],int n);
void sortId(int index, int i, int array[]);
void sortNames(int index, int i, char names[][20]);
void sortSurnames(int index, int i, char surnames[][20]);
void sortDepartment(int index, int i, char department[][20]);
void searchByNameAndSurname(int n, int id[], char names[][20], char surnames[][20], char department[][20], int grades[], char searchName[20], char searchSurname[20]);
void searchByDepartmentAndGrade(int n, int id[], char names[][20], char surnames[][20], char department[][20], int grades[], char searchDepartment[20], int gradeSearch);
void searchTopStudents(int n, int id[], char names[][20], char surnames[][20], char department[][20], int grades[], char searchDepartment[20],int number);

int main(){
    int n;
    scanf("%d",&n);

    int id[n], grade[n], searchGrade, number;
    char name[n][20], surname[n][20], class[n][20];

    char searchName[20], searchSurname[20];
    char searchDepartment[20];

    read(n,id,name,surname,class,grade);

    scanf("%s %s", searchName, searchSurname);
    searchByNameAndSurname(n, id, name, surname, class, grade, searchName, searchSurname);

    scanf("%s %d", searchDepartment, &searchGrade);
    searchByDepartmentAndGrade(n, id, name, surname, class, grade, searchDepartment, searchGrade);

    sort(id, name, surname, class, grade ,n);
    scanf("%s %d", searchDepartment, &number);
    searchTopStudents(n, id, name, surname, class, grade, searchDepartment, number);

}

void searchByNameAndSurname(int n, int id[], char names[][20], char surnames[][20], char department[][20],int grades[], char searchName[20], char searchSurname[20]){
    for(int i=0; i<n; i++){
        if(strcmp(names[i],searchName)==0 && strcmp(surnames[i],searchSurname)==0){
            printf("%d ", id[i]);
            printf("%s ", names[i]);
            printf("%s ", surnames[i]);
            printf("%s ", department[i]);
            printf("%d ", grades[i]);
            printf("\n");
        }
    }
}

void searchByDepartmentAndGrade(int n, int id[], char names[][20], char surnames[][20], char department[][20], int grades[], char searchDepartment[20], int gradeSearch){
    for (int i=0; i<n; i++){
        if (strcmp(department[i],searchDepartment)==0 && grades[i]>gradeSearch){
            printf("%d ", id[i]);
            printf("%s ", names[i]);
            printf("%s ", surnames[i]);
            printf("%s ", department[i]);
            printf("%d ", grades[i]);
            printf("\n");
        }
    }
}

void searchTopStudents(int n,int id[],char names[][20],char surnames[][20],char department[][20],int grades[],char searchDepartment[20],int number){
    int cnt=0;
    for(int i=0; i<n; i++){
        if(strcmp(department[i],searchDepartment)==0){
            printf("%d ",id[i]);
            printf("%s ",names[i]);
            printf("%s ",surnames[i]);
            printf("%s ",department[i]);
            printf("%d ",grades[i]);
            printf("\n");
            cnt++;
        }

        if(cnt==number)
            break;
    }
}

void sortId(int index, int i, int array[]){
    int temp;
    temp=array[i];
    array[i]=array[index];
    array[index]=temp;
}

void sortNames(int index,int i,char names[][20]){
    char temp[20];
    strcpy(temp, names[i]);
    strcpy(names[i],names[index]);
    strcpy(names[index],temp);
}

void sortSurnames(int index,int i,char surnames[][20]){
    char temp[20];
    strcpy(temp, surnames[i]);
    strcpy(surnames[i],surnames[index]);
    strcpy(surnames[index],temp);
}

void sortDepartment(int index,int i,char department[][20]){
    char temp[20];
    strcpy(temp, department[i]);
    strcpy(department[i],department[index]);
    strcpy(department[index],temp);
}

void sort(int id[],char name[][20],char surname[][20],char department[][20],int grades[],int n){
    int temp;
    for(int i=0; i<n-1; i++){
        int minIndex = i;
        for(int j=i+1; j<n; j++){
            if (grades[j] > grades[minIndex])
                minIndex = j;
        }
        temp=grades[i];
        grades[i]=grades[minIndex];
        grades[minIndex]=temp;
        sortId(minIndex,i,id);
        sortNames(minIndex,i,name);
        sortSurnames(minIndex,i,surname);
        sortDepartment(minIndex,i,department);
    }
}

void read(int n,int id[],char name[][20],char surname[][20],char department[][20],int grades[]){
    for(int i=0; i<n; i++){
        scanf("%d", &id[i]);
        scanf("%s", name[i]);
        scanf("%s", surname[i]);
        scanf("%s", department[i]);
        scanf("%d", &grades[i]);
        }
}