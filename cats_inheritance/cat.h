//
// Created by yuval on 05/08/2020.
//

#ifndef REFRESHING_PROJECT_CAT_H
#define REFRESHING_PROJECT_CAT_H


class Cat {

protected:
    const char *name;
    const char *color;
    double mus_length;

public:
    explicit Cat(const char* name, const char* color, double mus_length);
    Cat(const Cat &other);
    Cat(Cat &&other);
    ~Cat();

    const Cat& operator=(const Cat &other);
    const Cat& operator=(Cat &&other);
    void show() const;

    const char* getName() const;
    const char* getColor() const;
    int getMusLength() const;

    void setName(const char* name);
    void setColor(const char* color);
    void setMusLength(int mus_length);
};


#endif //REFRESHING_PROJECT_CAT_H
