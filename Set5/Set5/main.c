//
//  main.c
//  Set5
//
//  Created by Jakub Korkosz on 20/11/2020.
//

#include <stdio.h>
#include <string.h>

typedef struct Rational{
    int num;
    int denum;
}Rational;

struct Student{
    char name[10];
    char lastname[20];
    int semester;
};
struct Length{
    int meters;
    int cm;
};
typedef struct Time{
    int hours;
    int minutes;
    int seconds;
}Time;

//MARK: - Time
struct Time setTime(int hours, int minutes, int seconds ){
    Time time;
    time.hours = hours;
    time.minutes = minutes;
    time.seconds = seconds;
    return time;
}
void printTime(Time* t){
    printf("Hours: %d\tMinutes: %d\tSeconds: %d\n",t->hours,t->minutes,t->seconds);
}

void printTimeDifference( Time* t1, Time* t2){
    Time difference;
    if(t1->seconds - t2->seconds <0){
        difference.seconds = 60 + t1->seconds - t2->seconds;
        t1->minutes -= 1;
    }
    else{
        difference.seconds = t1->seconds - t2->seconds;
    }
    if(t1->minutes - t2->minutes <0){
        difference.minutes = 60 + t1->minutes - t2->minutes;
        t1->hours -= 1;
    }
    else{
        difference.minutes = t1->minutes - t2->minutes;
    }
    if(t1->hours - t2->hours <0){
        difference.hours = t1->hours - t2->hours * -1;
    }
    else{
        difference.hours = t1->hours - t2->hours;
    }
    
    printf("The time difference is:\n");
    printTime(&difference);
}

//MARK: - Students
struct Student setStudent(char* name, char* lastname, int semester){
    struct Student student;
    strcpy(student.lastname, lastname);
    strcpy(student.name,name);
    student.semester = semester;
    return student;
}

int compareStudents(struct Student* lhstudent, struct Student* rhstudent){
    // Returns 0 for equal or difference between letters from name or lastname.
    if(strcmp(lhstudent->lastname, rhstudent->lastname)==0){
        if(strcmp(lhstudent->name, rhstudent->name)==0){
            if(lhstudent->semester == rhstudent->semester){
                return 0;
            }
                else{
                if(lhstudent->semester > rhstudent->semester){
                    return 1;
                }
                else return -1;
                }
        }
            else return strcmp(lhstudent->name, rhstudent->name);
        }
        else return strcmp(lhstudent->lastname, rhstudent->lastname);
    
}

//MARK: -Rational values

struct Rational setValue(int a, int b){
    struct Rational tmp;
    tmp.denum = b;
    tmp.num = a;
    return tmp;
}

void printRational(Rational* rat){
    printf("%d\t%d\n",rat->num,rat->denum);
}
struct Rational sumRat(Rational* rat, Rational* rat2){
    int denom = rat->denum * rat2->denum;
    int numer = rat->denum * rat2->num + rat->num * rat2->denum;
    return setValue(numer, denom);
}
struct Rational differenceRat(Rational* rat, Rational* rat2){
    int denom = rat->denum * rat2->denum;
    int num = rat->num * rat2->denum - rat2->num * rat->denum;
    return setValue(num, denom);
}
struct Rational productRat(Rational* rat, Rational* rat2){
    int num = rat->num * rat2->num;
    int denum = rat->denum * rat2->denum;
    return setValue(num, denum);
}
struct Rational quotientRat(Rational* rat, Rational* rat2){
    int num = rat->num * rat2->denum;
    int denum = rat2->denum * rat->num;
    return setValue(num, denum);
}
struct Rational getRationalFromUser(){
    int num = 0 , denum = 0;
    printf("Insert numerator _space_ denominator\n");
    scanf("%d%d",&num,&denum);
    return setValue(num, denum);
}
double calculateRational(Rational* rat){
    return (double)rat->num/(double)rat->denum;;
}
int compareRational(Rational* rat, Rational* rat2){
    int num1 = rat->num * rat2->denum;
    int num2 = rat2->num * rat2->denum;
    if(num1>num2){
        return 1;
    }
    if(num2>num1){
        return -1;
    }
    else return 0;
}
//MARK: - Length
struct Length setLength(int m, int cm){
    struct Length tmp;
    tmp.cm = cm;
    tmp.meters = m;
    return tmp;
}
void printLenght(struct Length* l){
    printf("Meters: %d\t Centimeters: %d\n",l->meters,l->cm);
}

int compareLenght(struct Length* l1, struct Length* l2){
    int d1 = l1->meters * 100 + l1->cm;
    int d2 = l2->meters * 100 + l2->cm;
    if(d1>d2) return 1;
    if(d2>d1) return -1;
    else return 0;
}
struct Length addLength(struct Length* l1, struct Length* l2){
    int met = l1->meters + l2->meters;
    int cmet = l2->cm + l1->cm;
    if(cmet>=100){
        cmet -= 100;
        met += 1;
    }
    return setLength(met, cmet);
}
struct Length substractLength(struct Length* l1, struct Length* l2){
    int met = l1->meters - l2->meters;
    int cmet = l2->cm - l1->cm;
    if (cmet <0) {
        cmet = 100 -cmet;
        met -= 1;
    }
    return setLength(met, cmet);
}

//MARK: - Main function
int main(int argc, const char * argv[]) {
   /* struct Rational rat = setValue(5, 7);
    printRational(&rat);
    struct Rational ration = setValue(19, 15);
    printf("%d\t%d\n",ration.num,ration.denum);
    struct Rational fromuser = getRationalFromUser();
    printRational(&fromuser);
    printf("Inputed rational number equals: %lf\n",calculateRational(&fromuser));
    printf("Comparison: %d\n",compareRational(&rat, &fromuser));
    
    Time t1 = setTime(6, 20, 12);
    Time t2 = setTime(5, 15, 8);
    printTimeDifference(&t1, &t2);
    
    struct Student stud = setStudent("Jakub", "Jakubowski", 1);
    struct Student stud2 = setStudent("Jakub", "Jakubowski", 1);
    struct Student stud3 = setStudent("Stachu", "Jonas", 7);
    printf("Same: %d\n",compareStudents(&stud, &stud2));
    printf("Other: %d\n",compareStudents(&stud, &stud3));
    
    struct Length l1 = setLength(15, 20);
    struct Length l2 = setLength(7, 90);
    struct Length add = addLength(&l1, &l2);
    printLenght(&add);
    */
        return 0;
}
