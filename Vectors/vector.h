
template<typename T>
class Vector{
    T *arr;
    //current size
    int cs;
    //max size
    int ms;

public:
    Vector(int max_size=1){
        cs=0;
        ms=max_size;
        arr = new T[ms];
    }

    void push_back(int d){
        if(cs == ms){
            int *oldArr = arr;
            ms *= 2;
            arr = new T[ms];
            for(int i=0; i<cs; i++){
                arr[i] = oldArr[i];
            }
            delete [] oldArr;
        }

        arr[cs] = d;
        cs++;

    }

    void pop_back(){
        if(this->isEmpty()){
            cs--;
        }
    }

    bool isEmpty() const {
        return (cs == 0);
    }

    //Front, Back, At(i), []
    T front() const {
        return arr[0];
    }
    T back() const {
        return arr[cs-1];
    }

    T at(int i) const {
        return arr[i];
    }

    int size() const{
        return cs;
    }

    int capacity() const {
        return ms;
    }

    T * operator[](const int i){
        return &arr[i];
    }
};