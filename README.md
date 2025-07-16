# Metin Analiz Uygulamaları

Oluşturmuş olduğum bu uygulamalar metinler üzerinde çeşitli analizler yapmaktadır. Her uygulama farklı bir analiz üzerine temellenmiştir.
Aşağıda oluşturmuş olduğum bu uygulamaların çalışma mantığının daha iyi anlaşılabilmesi için çeşitli test senaryoları mevcuttur.

# text_analyzing_0

##Test 1:
* Girdi 1: "merhaba millet nerelerdesiniz"
* Girdi 2: "merhaba millet iyiyim"
* Çıktı: [{29, 21}, {0}, {0.666667}, {Yüksek}]

##Test 2:
* Girdi 1: "Gece hava serindi ve parkta sakince oturdum"
* Girdi 2: "Sabah Parkta yeterince egzersiz yaptım ama Hava serindi"
* Çıktı: [{43, 55}, {2}, {0.46291}, {Orta}]

##Test 3:
* Girdi 1: "Kediler su bulmakta yeteneklidir"
* Girdi 2: "Kitap okumak zihni dinlendirir"
* Çıktı: [{32, 30}, {0}, {0}, {Düşük}]

##Test 4:
* Girdi 1: "Merhaba millet Ve nasıl gidiyor"
* Girdi 2: "Merhaba millet ve Nasıl gidiyor"
* Çıktı: [{31, 31}, {2}, {1}, {Yüksek}]

##Test 5:
* Girdi 1: ""
* Girdi 2: "dolu metin"
* Çıktı: "Boş metinden dolayı benzerlik hesaplanamaz."

##Test 6:
* Girdi 1: "ve Ve ve veve"
* Girdi 2: "ve veya ama yinede"
* Çıktı: [{13, 18}, {6}, {0}, {Düşük}]

# text_analyzing_1

##Test 1:
* Girdi_1 : "kelek ada kazan gezegen"                	
* Çıktı_1 : [{gezegen, 7}{ada, 3}{kelek, ada}{e, 5}{23}]

##Test 2:
* Girdi_2 : "12221 ev tat 7887 565" 		
* Çıktı_2 : [{12221, 5}{ev, 2}{12221, tat, 7887, 565}{2, 3}{21}]

##Test 3:
* Girdi_3 : "merhaba elimde 10 metre kalem var" 	
* Çıktı_3 : [{merhaba, 7}{10, 2}{}{e, 6}{33}]

##Test 4:
* Girdi_4 : " " 				
* Çıktı_4 : [{, 0}{, 0}{}{, 0}{1}]

##Test 5:
* Girdi_5 : "55 !" 				
* Çıktı_5 : [{55, 2}{!, 1}{55, !}{5, 2}{4}]

##Test 6:
* Girdi_6 : "!@#$$%" 			
* Çıktı_6 : [{!@#$$%, 6}{!@#$$%, 6}{}{, 0}{6}]

##Test 7:
* Girdi_7 : "aaaaa bbbb ccc" 			
* Çıktı_7 : [{aaaaa, 5}{ccc, 3}{aaaaa, bbbb, ccc}{a, 5}{14}]


# text_analyzing_2
##Test 1:
* Girdi: "merhaba ve millet"
* Çıktı: [{merhaba -> emhrbaa, ve -> ev, millet -> imllte},{e, 3},{merhaba, 6},{1, ve},{17}]

##Test 2:
* Girdi: "123 aaaBbc 45"
* Çıktı: [{123 -> 213, aaaBbc -> aaBacb, 45 -> 54},{a, 3},{aaaBbc, 4},{2, 123, 45},{13}]

##Test 3:
* Girdi: "karAdeniz"
* Çıktı: [{karAdeniz -> akAredinz},{k, 1},{karAdeniz, 9},{0, },{9}]

##Test 4:
* Girdi: "aaaa bbb cc"
* Çıktı: [{aaaa -> aaaa, bbb -> bbb, cc -> cc},{a, 4},{aaaa, 1},{0, },{11}]

##Test 5:
* Girdi:" "
* Çıktı: [{}, {, 0}, {, 0}, {0, }, {1}]

##Test 6:
* Girdi:"!@#$&*()"
* Çıktı: [{!@#$&*() -> @!$#*&)(},{, 0},{!@#$&*(), 8},{1, !@#$&*()},{8}]

##Test 7:
* Girdi:"hello 124 world!"
* Çıktı: [{hello -> ehllo, 124 -> 214, world! -> owlr!d},{l, 3},{world!, 6},{2, 124, world!},{16}]

# text_analyzing_3

##Test 1:
* processText("Bu bir test! Metinde, fazla ve karakteri var.");
  
##Test 2:
* processText("test test test test test test test test test.");
  
##Test 3:
* processText("1234 Bu metin !!! ??? karakterlerinden Kelimeler elde eder.");
  
##Test 4:
* processText("!!!! ??? ..");
  
##Test 5:
* processText(" ");
  
##Test 6:
* processText("A A A A A A a a a a a Aa aA");
