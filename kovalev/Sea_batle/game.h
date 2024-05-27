#pragma once
#include <vector>
class player
{
    static const int SIZE_POLE=10;
    protected:
    int** MY_pole;
    int** Kuda_palil;
    int** NOT_MY_pole;
    static std::vector<std::vector<std::pair<int,int>>> ships1;
    static std::vector<std::vector<std::pair<int,int>>> copy_ships1;
    static std::vector<std::vector<std::pair<int,int>>> ships2;
    static std::vector<std::vector<std::pair<int,int>>> copy_ships2;
    int count_in=0;//count попаданий
    public:
    player();
    ~player();
    void copy_not_my_pole(const player* A);//pointer!!
    void cheating();
    bool check_free_cube_for_set(int i, int j);
    int count_heart();
    virtual void attack()=0;
    virtual void set_ship()=0;
    void Kill_ship(int f, int s);
    friend std::ostream& operator<<(std::ostream& out, const player* a);//pointer!!
};
class Bootinok: public player
{   public:
    void attack();
    void set_ship();
    private:
    int last_i=-1;
    int last_j=-1;
    int naprav=0;
    bool last_hod=0;
    bool ship_last_hod=1;
};
class Geniy: public player
{   public:
    void set_ship();
    void attack();
    
};
