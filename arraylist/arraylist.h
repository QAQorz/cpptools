class ArrayList{
public:
    ArrayList();
    explicit ArrayList(unsigned);
    ArrayList(const ArrayList&);
    ~ArrayList();
    int& operator[](unsigned);

    unsigned size();
    bool empty();
    void resize(unsigned);
    void push_back(int);
    void pop_back();
    void clear();
private:
    unsigned MAXSIZE, sz;
    int* arr;
};