import math
from sys import argv


def calculate_rms(mean, sd):
    return math.sqrt((mean ** 2) + (sd ** 2))


def approximate_harmonic_mean(n_old, n_new, sd_old, sd_new, a_old, a_new, h_old, new_value):
        divide = 1/new_value
        divide += ((1 / h_old) * n_old)
        if (divide == 0):
            print("You can't divide by 0, please check value and retry.\n")
            exit(84)
        return(n_new / divide)


# def approximate_harmonic_mean(n_old, n_new, sd_old, sd_new, a_old, a_new, h_old):
#     reciprocal_harmonic_mean = 1 / h_old
#     reciprocal_new_value = 1 / a_new

#     updated_reciprocal_harmonic_mean = ((reciprocal_harmonic_mean * n_old) + reciprocal_new_value) / (n_old + 1)
#     updated_harmonic_mean = 1 / updated_reciprocal_harmonic_mean

#     return updated_harmonic_mean


def main(argv):
    try:
        argv.pop(0)
        n, a, h, sd = map(float, argv)
        n = int(n)
    except:
        print("Please enter 4 arguments or -h flag")
        exit(84)    

    while True:
        n_old = n
        sd_old = sd
        a_old = a
        h_old = h

        next_value = input("Enter next value: ")
        if next_value == "END":
            break
        else:
            n += 1
            try:
                new_value = float(next_value)
            except:
                print("Please enter a float as argument.")
                exit(84)
            sd = (((n - 1) * (sd ** 2) + (new_value - a) * (new_value - a)) / n)
            if sd >= 0:
                sd = math.sqrt(sd)
            else:
                print("Error: negative standard deviation")
                exit(84)
            a = ((n - 1) * a + new_value) / n
            rms = calculate_rms(a, sd)
            harmonic_mean = approximate_harmonic_mean(n_old, n, sd_old, sd, a_old, a, h_old, new_value)
            print(f"    Number of values:   {n}")
            print(f"    Standard deviation: {sd:.2f}")
            print(f"    Arithmetic mean:    {a:.2f}")
            print(f"    Root mean square:   {rms:.2f}")
            print(f"    Harmonic mean:      {harmonic_mean:.2f}")
            print()


if __name__ == "__main__":
    if len(argv) != 5 or argv[1] == "-h":
        print("""USAGE
    ./104neutrinos n a h sd

DESCRIPTION
    n       number of values
    a       arithmetic mean
    h       harmonic mean
    sd      standard deviation""")
    else:
        main(argv)
