export module extended;

export int Multiply(int a, int b) {
    return a * b;
}

export int Division(int a, int b) {
    if (b != 0) {
        return a / b;
    }

    return -1;
}
