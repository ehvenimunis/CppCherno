# Flyweight Design Pattern

**"Flyweight Pattern"** Flyweight pattern, nesne üretiminden kaynaklı bellek kullanımını minimize etmemizi sağlayan bir tasarım kalıbıdır. Eğer bellek tüketimi, çok fazla nesnenin bir arada ele alınmasından kaynaklı ortaya çıkıyorsa burada flyweight tasarım kalıbını kullanabiliriz.

Flyweight tasarım kalıbı havuz mantığıyla çok kullanılan nesnelerin creation işlemini azaltmayı sağlar.

Flyweight tasarım kalıbının yapısına değinecek olursak, bu patternde FlyweightFactory dediğimiz bir classımız vardır. Bu class içerisinde Flyweight classının kalıtımını alan classların yani tekrar tekrar üreteceğimiz classların listesini tutar ve bir metot ile clienta bu listeye erişim verir. Client bu metot üzerinden bir nesne üretmek istediği zaman, metot önce bu nesne elindeki listede yani nesne havuzunda var mı diye bakar. Var ise bu listeden verir. Yok ise de önce bu listeye ekler sonra da eklediğini verir.

Yani kısaca . . .

    Bir nesne üretmek istediğin zaman FlyweightFactory üzerinden üret.
    Eğer nesne flyweightFactroy içerisindeki havuzda yer alıyorsa nesneyi sana bu havuzdan döndürecektir. Yok ise önce havuza ekleyip sonra döndürecektir.
    Havuzdaki nesnelerin common olanları havuzdan alındığı şekilde kullanılır. Spesifikasyon gerekenleri de havuzdan alındıktan sonra customize edilir.
