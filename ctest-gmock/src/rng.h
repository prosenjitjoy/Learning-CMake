#ifndef RNG_H
#define RNG_H

class RandomNumberGenerator {
public:
    virtual int Get() = 0;
    virtual ~RandomNumberGenerator() = default;
};

#endif // RNG_H
