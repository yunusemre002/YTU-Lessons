from prettytable import PrettyTable     # Create pretty Table :)
n=0

def polinomAl(fonk):
    n = int(input("Polinomun en yuksek derecesini giriniz : "))
    for i in range(n+1,0,-1):
        add = int(input("Derecesi {} olan terimin katsayisini giriniz :".format(i-1)))
        fonk += [add]  # !!! EKLEME İŞLEMİ İÇİN [İÇİNDE] YAZMALIYIZ.

def functions(a,fonk,n):
    fnc = i = 0
    while(i <= n):
        fnc = fnc + (fonk[i] * pow(a, i))         # (x^0)*katsayısı + (x^1)*katsayısı + (x^2)*katsayısı
        i += 1
    return fnc

def turevAl(turev,fonk):
    i=0
    for i in (1,n+1,+1):
        turev[i-1] = fonk[i] * i


# ---------------GRAFİK YÖNTEMİ----------------------------
def grafikYontemi(fonk):
    x = float(input("Enter the starting value = "))
    delta = float(input("Enter the Delta x = "))
    eps = float(input("Enter the Epsilon value = "))

    x1 = x + delta
    fonk0 = functions(x, fonk, n)
    fonk1 = functions(x1, fonk, n)

    table = PrettyTable()
    table.field_names = ['delta', 'x', 'f(x)', 'x+1', '|f(x)-f(x+1)|']
    table.add_row([delta, x, fonk0, x1, abs(fonk0 - fonk1)])      # abs(-a) = |-a| = a   //Absolute value

    while (abs(fonk0-fonk1) > eps):           # Do above while |f(x)-f(x+1)| > epsilon      (|Xk - Xk+1|)
        x = x1
        x1 = x + delta
        fonk0 = functions(x,fonk,n)
        fonk1 = functions(x1,fonk,n)
        table.add_row([delta, x, fonk0, x1, abs(fonk0 - fonk1)])
        if (fonk1 * fonk0 < 0):              # if f(x) * f(x+1) < 0 , so there are opposite sign. + - or - +
            x1 = x1 - delta                 # x1 goes to one step back (Because new series start from them(Xk))
            delta = delta / 2               # And Delta must be lower to find most nearest value

    print(table)
    print("Denklemin Kökü = ", x1)


while(True):
    print("\nKök Bulma Yontemleri(Kapalı)\n\t1-)Grafik Yontemi\n\t2-)Yariya Bolme Yontemi\n\t3-)Regula False Yontemi\n"
          "Kök bulma yöntemleri (Açık)\n\t4-)Newton Raphson Yontemi\n\t5-)Basit iterasyon\n\t6-)Sekant(Kiriş)\n")

    inpt = input("Lutfen bir secim yapiniz (Cikmak icin Q)")

    fonk = []
    if inpt == -1:
        exit()
    elif inpt == "1":
        print("\t_Grafik Yontemi_\n")
        polinomAl(fonk)
        grafikYontemi(fonk)

    elif inpt == "2":
        printf("\t_Yariya Bolme Yontemi_\n");
        polinomAl(fonk);
        bisection(fonk);

    elif inpt == "3":
        print("\t_Regula False Yontemi_\n")
        polinomAl(fonk)
        RegulaFalse(fonk)
    elif inpt == "4":
        print("\t_Newton Raphson Yontemi_\n");
        polinomAl(fonk);
        NewtonRaphson(fonk);

    elif inpt == "5":
        print("\t_Matrisin inversinin alinmasi_")


    elif inpt == "6":
        printf("\t_Gauss Jordan_")
        gaussJordan()

    elif inpt == "7":
        printf("\t_Trapez Yontemi_")
        polinomAl(fonk)
        Trapez(fonk)

    elif inpt == "8":
        printf("\t_Simpson Yontemi_\n")
        polinomAl(fonk)
        Simpson(fonk)
    else:
        print("Yanlış bir seçim yaptınız")


