# papildoma_uzduotis
Egzamino (išankstinė) užduotis

# Skaičiavimas kiek kartų kievienas skirtingas žodis pasirodo tekste

Užduočiai buvo pasirinktas BBC straipsnis [How maths can help you wrap your presents better](https://www.bbc.com/future/article/20251212-how-maths-can-help-you-wrap-your-presents-better). Tekstas nukopijuotas į txt failą.  

Užduočiai pasirinktas `std::map`, nes jis leižia patogiai saugoti skirtingus žodius kaip raktus ir jų pasikartojimų skaičių kaip reikšmes (["žodis":"pasikartojimų skaičius"]). Map neleidžia raktams dubliuotis, to dėl saugome tik unikalius žožius.  


# Cross-reference lentelė
Užduočiai buvo pasirinktas straipsnis [Understanding URLs](https://www4.uwsp.edu/english/cwilliams/docu_online.html). Tekstas nukopijuotas į txt failą.

Šiai užduočiai atlikti buvo pasinaudotas `std::map` iš WordCount.cpp, kad surasti unikalius žodžius ir jų kartojimosi reikšmę (kadangi tis reikalauja i lentelė įterpti žodius,kurie kartojosi daugiau nei 1 kartą).  
`std::set` buvo naudojamas eilučių numeriams saugoti cross-reference dalyje, nes jis neleidžia pasikartojančių reikšmių ir automatiškai rikiuoja reikšmes didėjimo tvarka. Todėl nereikia papildomo tikrinimo ar rūšiavimo išvedimo metu.


# URL adresų suradimas tekste
Šiai uzduoties daliai buvo naudojamas


## Kaip veikia programa
Paleidus programą vartotojas mato meniu.  
![menu](./screenshots/image.png)  

Suvedus ***1.*** programa sugeneruoja failą su žodžiais ir kiek kartų jis pasikartojo tekste.  
![wordCount output](./screenshots/image-1.png)  

Suvedus ***2.*** programa sugeneruoja failą su cross-reference tipo lentele. Joje nurodytas žodis ir kuriose teksto eilutėse jį galima rasti.  
![crossReference](./screenshots/image-2.png)  

Suvedus ***3.*** programa sugeneruoja failą su URL adresų sąrašu.  
![urlList](./screenshots/image-3.png)  

Suvedus ***4.*** programa baigia darbą.  