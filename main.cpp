#include "knight.h"
void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue) {
    cout << "HP=" << HP
        << ", level=" << level
        << ", remedy=" << remedy
        << ", maidenkiss=" << maidenkiss
        << ", phoenixdown=" << phoenixdown
        << ", rescue=" << rescue << endl;
}
int readNumber(int map[],string len){
    int j = 1;
    int start = 0;
    int end = len.find(" ");
    while (end != string::npos) {
        string str_num = len.substr(start, end - start);
        map[j] = stoi(str_num);
        j++;
        start = end + 1;
        end = len.find(" ", start);
    }
    string str_num = len.substr(start, end);
    map[j] = stoi(str_num);
    j++;
    return j;
}
/*hàm trong while*/
void checkLevel(int &level){
  if(level>10) level=10;
}

/*mã sự kiện từ 1 đến 5*/
int lvO(int local){
  int b = local%10;
  int level = local > 6 ? (b > 5 ? b : 5) : b;
  return level;
}
int sl(int levelO,int level){
  if(level > levelO){
    return 1;
  } else if(levelO == level){
    return 0;
  } else if(level < levelO){
    return -1;
  }
  return 0;
}
int damage1to5(int HP,int levelO,int &phoenixdown,int MaxHP,int codeEvent, int &rescue){
  double baseDamage ;
  switch (codeEvent) {
  case 1:
    baseDamage=1;
    break;
  case 2:
    baseDamage=1.5;
    break;
  case 3:
    baseDamage=4.5;
    break;
  case 4:
    baseDamage=7.5;
    break;
  case 5:
    baseDamage=9.5;
    break;
  }
  int damage=baseDamage*levelO*10;
  HP=HP-damage;
  if(HP <= 0 && phoenixdown == 0){
    rescue = 0;
    return HP;
  } else if(HP <= 0 && phoenixdown > 0){
    phoenixdown--;
    rescue = -1;
    return MaxHP;
  } else ;
  return HP;
}
void checkHP(int HP,int &rescue,int &phoenixdown,int &check,int MaxHP,int &counter){
  if(HP<0 && phoenixdown < 1) rescue =0;
  if(HP<0 && phoenixdown > 1) {
    phoenixdown--;
    HP=MaxHP;
    counter=0;
    check=0;
  }
}
/*Sự kiện 6*/
int lowpeopleHP(int HP){
    if(HP < 5){
      HP=1;
      return HP;
    }else{
      HP=HP/5;
      return HP;
    }
}
void cure(int &check_people,int &check_frog, int &maidenkiss, int &remedy, int &regLevel,int &counter,int &counterf, int &HP ,int &level){
    //thuốc giải
    if(check_people==1 && remedy > 0){
        check_people = 0;
        remedy--;
        counter=0;
        HP=HP*5;
    } else ;
    if(check_frog==1 && maidenkiss > 0){
        check_frog = 0;
        maidenkiss--;
        counterf=0;
        level=regLevel;
    }
}
// sự kiện 11
bool prime(int n) 
{ 
    if(n<=1) return 0;
    for(int i=2;i<n;i++){
        if(n%i==0) return 0;
    }
    return 1;
} 
int prePrime(int HP)
{ 
    int prePrime = HP; 
    bool found = false; 
    if (HP <= 1) 
        return 2; 
    while (!found) 
    { 
        prePrime++; 
        if (prime(prePrime)) found = true; 
    } 
    return prePrime; 
} 
int MushMario(int level,int phoenixdown, int HP, int MaxHP){
  int n1=((level+phoenixdown)%5+1)*3;
  int s1=0;
  for(int i=0,j=99;i<n1;i++){
    s1=s1+j;
    j-=2;
  }
  HP=HP+(s1%100);
  HP=prePrime(HP);
  if(HP>MaxHP){
    return MaxHP;
  }
  return HP;
}
// sự kiện 12
int  Fibonacci_MushFibo(int HP){
     if (HP == 1) {
        return 1;
    } else {
        int pre = 0;
        int cur = 1;
        int next = 1;
        while (next < HP) {// coi lại 
            pre = cur;
            cur = next;
            next = pre + cur;
        }
        return cur;
    }
}
void clam(int &item){
  item++;
  if(item>99) item=99;
}
// sự kiện 13 ms
void MushGhost(string mush_ghost, int line[], int &n2){
    ifstream inMush(mush_ghost);
    if(!inMush.is_open()){
    } else {
    int i=0;
    inMush>>n2;
    inMush.ignore();
    string line2;
    while(!inMush.eof()){
        getline(inMush,line2,',');
        line[i]=stoi(line2);
        i++;
    }}
    inMush.close();
}
int checkMountain(int len[],int n2,int &mtx,int &mti) {
    int max=len[0],j=0;
    for(int i=0;i<n2;i++){
        if(len[i]>max) {
        max=len[i];
        j=i;
        }
    }
    for(int i=0;i<j-1;i++){
        if(len[i]>len[i+1]) {
        mtx = -2; 
        mti = -3;
        return 0;
        }
    }
    for(int i=j;i<n2-1;i++){
        if(len[i]<len[i+1]) {
        mtx = -2; 
        mti = -3;
        return 0;
        }
    }
    mtx=max;
    mti=j;
    return 1;
}
void checkMush3_4(int len1[],int len[],int n2,int &maxi2,int &mini2,int &max2_3x,int &max2_3i){
    for (int i=0;i<n2;i++){
        if(len[i] < 0) {
          len1[i]=-len[i];
        } else len1[i]=len[i];
        len1[i]=(17*len1[i]+9)%257;
    }
    int max=len1[0];
    int min=len1[0];
    for (int i=0;i<n2;i++){
        if(len1[i]>max){
        max=len1[i];
        }
        if(len1[i]<min){
        min=len1[i];
        }
    }
    for(int i=0;i<n2;i++){
        if(max==len1[i]){
        maxi2=i;
        break;
        }
    }
    for(int i=0;i<n2;i++){
        if(min==len1[i]){
        mini2=i;
        break;
        }
    }
    max2_3x=-1;
    max2_3i=-1;
    int max2=len1[0];
    int max_i=0;
    for(int i=0;i<3;i++){
      if(len1[i]>max2){
        max2=len1[i];
        max_i=i;
      }
    }
    for(int i=0;i<3;i++){
      if(len1[i] > max2_3x && len1[i]!=max2){
        max2_3x=len1[i];
        max2_3i=i;
      }
    }
    if(max2_3x==-1) {
      max2_3x=-5;
      max2_3i=-7;
    }
} 
void Asclepius(string asclepius_pack, int r1,int c1,int &remedy, int &maidenkiss,int &phoenixdown){
  int M[10000];
  ifstream inasc(asclepius_pack); 
  inasc>>r1;
  inasc.ignore();
  inasc>>c1;
  for(int i=0;i<r1;i++){
    int k=0;
    for(int u=0;u<c1;u++){
      inasc>>M[u];
    }
    for(int u=0;u<c1;u++ ){
      if(M[u]==16){
        remedy++;
        k++;
      } else if(M[u]==17){
        maidenkiss++;
        k++;
      } else if(M[u]==18){
        phoenixdown++;
        k++;
      } else;
      if(k==3) break;
    }
  }
  inasc.close();
}
void merlin(string merlin_pack,int &HP,int MaxHP){
  ifstream inMerlin(merlin_pack);
   if(!inMerlin.is_open()){
    } else {
    int n9;
    inMerlin>>n9;
    inMerlin.ignore();
    string item_name;
    string merlin="merlin";
    for(int i=0;i<n9;i++){
      getline(inMerlin,item_name);
      for(int i=0;i<item_name.length();i++){
        item_name[i] = tolower(item_name[i]);
      }
      bool isItem = true;
      for(int i=0;i<6;i++){
        if(item_name.find(merlin[i])== string::npos){
          isItem=false;
          break;
        }
      }
      if(isItem==1){
        if(item_name.find("merlin")==string::npos){
          HP=HP+2;
        } else HP=HP+3;
        if(HP>MaxHP) HP=MaxHP;
      }
    }
  }
  inMerlin.close();
}
void checkInfo( int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown ,int & rescue){
  if(remedy>99) remedy=99;
  if(phoenixdown>99) phoenixdown=99;
  if(maidenkiss>99) maidenkiss=99;
  if(HP>999) HP=999;
  if(remedy<0 || phoenixdown<0 || maidenkiss<0 || level < 0 || HP<0) rescue=0;
}
void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue) {
    /*Khai báo biến mặc định */
    int map[10000];
    int knight_info[5];
    rescue=-1;
    int local=1;
    int levelO;
    int solo;
    int n2;
    int len[100];
    int len1[100];
    int maxi;
    int mini;
    int mtx;
    int mti;
    int maxi2;
    int mini2;
    int max2_3x;
    int max2_3i;
    int r1;
    int c1;
    int Arthur=0;
    int people;
    int Merlin=0;
    int j=1;
    int asclepius=0;
    int small;
    int large;
    /*Đọc file*/
    /*----Khai báo biến------*/
    string line;
    string line2;
    string mush_ghost;
    string merlin_pack;
    string asclepius_pack;
    int knigthLength;
    int mapLength;
    /*----Xử lí file--------*/
    ifstream inFile(file_input);
    if (!inFile.is_open()) {
        rescue=0;
    }
    getline(inFile,line);
    knigthLength = readNumber(knight_info,line);
    getline(inFile,line2);
    mapLength = readNumber(map,line2);
    getline(inFile,mush_ghost,',');
    getline(inFile,asclepius_pack,',');
    getline(inFile,merlin_pack);
    inFile.close();
    /*Thông tin hiệp sĩ*/
    HP=knight_info[1];
    level=knight_info[2];
    remedy=knight_info[3];
    maidenkiss=knight_info[4];
    phoenixdown=knight_info[5];
    int const MaxHP=HP;
    /*khai bao cac biên dếm*/
    int check_people=0;
    int counter=0;
    int check_frog=0;
    int counterf=0;
    int regLevel=level;
    int Lancelot=0;
    int iString=2;
    /*Xử lí trò chơi*/
    checkInfo(HP,level,remedy,maidenkiss,phoenixdown ,rescue);
    if(HP==999) Arthur=1;
    if(prime(HP)) Lancelot=1;
    while(rescue == -1){
      // cout<<map[local];
        switch (map[local]) {
        case 0:
            rescue = 1;
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            if(Arthur==1 || Lancelot==1) {
                level++;
                break;
            }
            levelO=lvO(local);
            solo = sl(levelO,level);
            if(solo == 1){
                level++;
            } else if (solo == 0){
                // Không làm gì cả
            } else if (solo == -1){
                HP = damage1to5(HP,levelO,phoenixdown,MaxHP,map[local],rescue);
            } else ;
            break;
        case 6:
            if(Arthur==1 || Lancelot==1) {
                level+=2;
                break;
            }
            if(check_frog==1 || check_people==1) break;
            levelO=lvO(local);
            solo = sl(levelO,level);
            if(solo == 1){
                level+=2;
            } else if (solo == 0){
                // Không làm gì cả
            } else if (solo == -1){
                check_people=1;
                counter=4;
                int HP_pre=HP;
                HP=lowpeopleHP(HP);
                if( remedy >= 1){
                    check_people = 0;
                    remedy--;
                    counter=0;
                    HP=HP_pre;
                } else {
                    if(HP<=0 && phoenixdown>0){
                        check_people = 0;
                        counter=0;
                        phoenixdown--;
                        HP=MaxHP;
                    } else if(HP<=0 && phoenixdown<0) rescue=0;
                }
            }
            break;
        case 7:
            if(Arthur==1 || Lancelot==1) {
                level+=2;
                break;
            }
            if(check_frog==1 || check_people==1) break;
            levelO=lvO(local);
            solo = sl(levelO,level);
            if(solo == 1){
                level+=2;
            } else if (solo == 0){
                // Không làm gì cả
            } else if (solo == -1){
                check_frog=1;
                counterf=4;
                regLevel=level;
                level=1;
                if(maidenkiss > 0){
                    maidenkiss--;
                    level=regLevel;
                    check_frog=0;
                } else;
            }
            break;
        case 11:
            HP=MushMario(level,phoenixdown,HP,MaxHP);
            break;
        case 12:
            HP=Fibonacci_MushFibo(HP);
            break;
        case 15:
            clam(remedy);
            break;
        case 16:
            clam(maidenkiss);
            break;
        case 17:
            clam(phoenixdown);
            break;
        case 18:
            if(Merlin!=1){
                merlin(merlin_pack,HP,MaxHP);
                Merlin=1;
            }
            break;
        case 19:
            if(asclepius!=1){
                Asclepius(asclepius_pack,r1,c1,remedy,maidenkiss,phoenixdown);
                asclepius=1;
            }
            break;
        case 99:
            if(Arthur==1) break;
            if(Lancelot==1){
                if(level>=8){
                level=10;
                rescue=-1;
                } else rescue=0;
            } else {
                if(level==10){
                rescue=-1;
                } else if(level<10) rescue=0; else;
            } 
            break;
        default:
            string myString = to_string(map[local]);
            if(myString.find("13")==0){
                while(myString[iString]){
                    if(HP > MaxHP) HP=MaxHP; else if(HP < 0 && phoenixdown>0){
                    phoenixdown--;
                    check_people = 0;
                    counter=0;
                    HP=MaxHP;
                    } else if (HP<0){
                        rescue = 0;
                        break;
                    } else ;
                    switch (myString[iString]){
                        case '1':
                            MushGhost(mush_ghost,len,n2);
                            large=len[0];
                            small=len[0];
                            for (int l=0;l<n2;l++){
                                if(len[l]<=small) {
                                    small=len[l];
                                    mini=l;
                                } else ;
                                if(len[l]>=large){
                                    large=len[l];
                                    maxi=l;
                                } else ;
                            }
                            HP=HP-(maxi+mini);
                            break;
                        case '2':
                            MushGhost(mush_ghost,len,n2);
                            checkMountain(len,n2,mtx,mti);
                            HP = HP - (mtx + mti);
                            break;
                        case '3':
                            MushGhost(mush_ghost,len,n2);
                            checkMush3_4(len1,len,n2,maxi2,mini2,max2_3x,max2_3i);
                            HP= HP - (maxi2+mini2);
                            break;
                        case '4':
                            MushGhost(mush_ghost,len,n2);
                            checkMush3_4(len1,len,n2,maxi2,mini2,max2_3x,max2_3i);
                            HP=HP - (max2_3x+max2_3i);
                            break;
                        default:
                            break;
                    }
                iString++;
                if(rescue==0) break;
                }
            }
            break;
        }
    iString=2;
    local++;  
    if(HP>999) HP=MaxHP;
    if(remedy>99) remedy=99;
    if(phoenixdown>99) phoenixdown=99;
    if(maidenkiss>99) maidenkiss=99;
    /*kiểm tra còn trạng thái ếch và người tí hon không*/
    if(counter==1 && check_people==1){
      check_people=0;
      HP=HP*5;
      if(HP>MaxHP){
        HP=MaxHP;
      }
    } else if(counter!=0){
      counter--;
    } else ;
    if(check_frog==1 && counterf==1){
      check_frog =0;
      level=regLevel;
    } else if(counterf!=0){
      counterf--;
    } else ;
    cure(check_people,check_frog, maidenkiss, remedy, regLevel,counter,counterf, HP ,level);
    checkLevel(level);
    checkHP(HP,rescue,phoenixdown,check_people,MaxHP,counter);
    if(local == mapLength && rescue==-1) rescue=1;
    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
    }
  return ;
}
