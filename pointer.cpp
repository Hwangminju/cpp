#include <iostream>

using namespace std;

void error (string s) {}

void (*efct) (string);

void f()
{
    efct = &error;
    efct("error");

    pf = &f1;
    pf("Hera");
}

void (*f1)(string) = &error;
void (*f2)(string) = error;

void g()
{
    f1("Vasa");
    (*f1)("Mary Rose");
}

void (*pf)(string);
void f1(string);
int f2(string);
void f3(int*);

using CFT = int(const void*, const void*);
void ssort(void* base, size_t n, size_t sz, CFT cmp)
{
    for (int gap=n/2; gap>0; gap/=2)
        for (int i=gap; i!=n; i++)
            for (int j=i-gap; j>=0; j-=gap) {
                char* b = static_cast<char*>(base);
                char *pj = b+j*sz;
                char *pjg = b+(j+gap)*sz;
                if (cmp(pjg,pj)<0) {
                    for (int k=0; k!=sz; k++) {
                        char temp = pj[k];
                        pj[k] = pjg[k];
                        pjg[k] = temp;
                    }
                }

            }
}

struct User {
    const char* name;
    const char* id;
    int dept;
};

vector<User> heads = {
    "Ritchie D.M.","dmr",11271,
    "Sethi R.","ravi",11272,
    "Szymanski T.G.","tgs",11273,
    "Schr yer N.L.","nls",11274,
    "Schr yer N.L.","nls",11275,
    "Kernighan","bwk",11276
};

void print_id(vector<User>& v)
{
    for (auto& x : v)
        cout << x.name << '\t' << x.id << '\t' << x.dept << '\n';
}

int cmp1(const void* p, const void* q)
{
    return strcmp(static_cast<const User*>(p)->name, static_cast<const User*>(q)->name);
}

int cmp2(const void* p, const void* q)
{
    return static_cast<const User*>(p)->dept - static_cast<const User*>(q)->dept;
}

int comp3(const User* p, const User* q)
{
    return strcmp(p->id, q->id);
}

int main()
{
    cout << "Heads in alphabetical order:\n";
    ssort(&heads[0],6,sizeof(User),cmp1);
    print_id(heads);
    cout << '\n';

    cout << "Heads in order of department number:\n";
    ssort(&heads[0],6,sizeof(User),cmp2);
}
