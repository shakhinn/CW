class CustomStack {
protected:
    int* mData;
private:
    int capacity;
    int n;
public:
    explicit CustomStack(){
        capacity = 0;
        mData = new int;
        n = -1;
    }

    bool pop(int &val){
        if(empty()){
            return false;
        }
        val = mData[n];
        n--;
        return true;
    }

    bool push(int a){
        if(n==capacity-1)
            extend(10);
        n++;
        mData[n] = a;
        return true;
    }

    int top(){
        if(empty()){
            //cout<<"error"<<endl;
            return 0 ;
        }
        return mData[n];
    }

    size_t size(){
        return n;
    }

    bool empty(){
        return n == -1;
    }

    void extend(int k){
        capacity = capacity+k;
        int* new_mass = new int[capacity+k];
        for(int i = 0; i<n; i++) {
            new_mass[i] = mData[i];
        }
        delete mData;
        mData = new_mass;

    }

    ~CustomStack(){
        delete[] mData;
    }

};


bool Makeoperation(char m, CustomStack& stack){
    int left = 0;
    int right = 0;
    switch (m){
        case '+':
            stack.pop(right);
            stack.pop(left);
            if(left == 0){
                cout<<"error"<<endl;
                return false;
            }
            stack.push(left+right);
            //cout<<left<<'+'<<right<<' '<<stack.top()<<endl;
            break;
        case '-':
            stack.pop(right);
            stack.pop(left);
            if(left == 0){
                cout<<"error"<<endl;
                return false;
            }
            stack.push(left-right);
            //cout<<left<<'-'<<right<<' '<<stack.top()<<endl;
            break;
        case '*':
            stack.pop(right);
            stack.pop(left);
            if(left == 0){
                cout<<"error"<<endl;
                return false;
            }
            stack.push(left*right);
            //cout<<left<<'*'<<right<<' '<<stack.top()<<endl;
            break;
        case '/':
            stack.pop(right);
            stack.pop(left);
            if(left == 0){
                cout<<"error"<<endl;
                return false;
            }
            stack.push(left/right);
            //cout<<left<<'/'<<right<<' '<<stack.top()<<endl;
            break;
        default: return false;
    }
    return true;
}

int main(){
    CustomStack stack;
    char str[200];
    char** tokes =  new char*[200];
    fgets(str, 200, stdin);
    int n = 0;
    char *pch = strtok (str, " ");
    while (pch != NULL){
        int h = strlen(pch);
        tokes[n] =  new char[h+2];
        strcpy(tokes[n++], pch);
        pch = strtok (NULL, " ");
    }
    for(int j = 0; j < n-1; j++){
        if(strlen(tokes[j]) > 1){
            int dig = 0;
            dig = atoi(tokes[j]);
            stack.push(dig);
            //cout<<"i pushed:"<<stack.top()<<endl;
        }
        else{
            if(isdigit(tokes[j][0])){
                int digit = 0;
                digit = atoi(tokes[j]);
                stack.push(digit);
                //cout<<"i pushed:"<<stack.top()<<endl;
            }
            if(tokes[j][0] == '*' || tokes[j][0] == '+' || tokes[j][0] == '-' || tokes[j][0] == '/'){
                if(!Makeoperation(tokes[j][0], stack)){
                    return 0;
                }
            }
        }
    }
    if(tokes[n-1][0] != '*' && tokes[n-1][0] != '+' && tokes[n-1][0] != '-' && tokes[n-1][0] != '/'){
        cout<<"error";
        return 0;
    }
    if(!Makeoperation(tokes[n-1][0], stack)){
        return 0;
    }


    if(stack.size()>0){
        cout<<"error";
        return 0;
    }
    cout<<stack.top();
    for(int i = 0; i < n; i++){
        delete[] tokes[i];
    }
    delete [] tokes;
    return 0;
}
