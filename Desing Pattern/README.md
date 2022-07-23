# C++ ile Design Pattern (Tasarım Kalıpları (Örüntüleri))


## **Creational** (Yaratılış)

Yaratılış kalıpları, nesneleri doğrudan oluşturmanıza değil, sizin için nesneler yaratan kalıplardır. Bu, belirli bir durum için hangi nesnelerin yaratılması gerektiğine karar vermede programınıza daha fazla esneklik sağlar. Yani yaratıcı-Oluşturucu tasarım desenleri, bir nesnenin ya da grubun esnek ve tekrar kullanılabilir biçimde nasıl oluşturucağı ile ilgilenir.

* ✓✓ **Singleton** pattern,  bir sınıf için sadece bir nesne oluşturmayı sağlar. Kaç kere obje oluşturulursa oluşturulsun, ilk oluşturulan hali ile geri dönme durumudur
* ✓✓ **Factory method** pattern, oluşturulacak tam sınıfı belirtmeden nesneleri oluşturur. Var olan şablona uygun olarak nesneler yaratmaktadır.
* ✓✓ **Abstract factory**  pattern, ortak gruplar, ortak bir temaya sahip olan sınıfların yaratılış biçimini hedefler.
* ✓✓ **Builder** pattern, karmaşık nesneler inşa eder böylece karmaşık bir kurucu üyeye veya argümanlara ihtiyaç duymayız.
* ✓✓ **Prototype** pattern, mevcut bir nesneyi klonlayarak nesneler oluşturur.

## **Behavioral** (Davranışsal)

Bu tasarım desenlerinin çoğu, özellikle nesneler arasındaki iletişim ile ilgili yapılardır.

* ✓✓ **Chain of Responsibility** delegates commands to a chain of processing objects.
* ✓✓ **Command** bir isteği nesneye dönüştürerek, isteğin kullanıcı sınıfları tarafından rahatça erişilebilmesi sağlar.
* ✓✓ **Interpreter** implements a specialized language.
* ✓✓ **Iterator** accesses the elements of an object sequentially without exposing its underlying representation.
* ✓✓ **Mediator** allows loose coupling between classes by being the only class that has detailed knowledge of their methods.
* ✓✓ **Memento** provides the ability to restore an object to its previous state (undo).
* ✓✓ **Observer** is a publish/subscribe pattern which allows a number of observer objects to see an event.
* ✓✓ **State** allows an object to alter its behavior when its internal state changes.
* ✓✓ **Strategy** allows one of a family of algorithms to be selected on-the-fly at runtime.
* ✓✓ **Template** method defines the skeleton of an algorithm as an abstract class, allowing its subclasses to provide concrete behavior.
* ✓✓ **Visitor** separates an algorithm from an object structure by moving the hierarchy of methods into one object.

## **Structural**
These concern class and object composition. They use inheritance to compose interfaces and define ways to compose objects to obtain new functionality.

* ✓✓ **Adapter** allows classes with incompatible interfaces to work together by wrapping its own interface around that of an already existing class.
* ✓✓ **Bridge** decouples an abstraction from its implementation so that the two can vary independently.
* ✓✓ **Composite** composes zero-or-more similar objects so that they can be manipulated as one object.
* ✓✓ **Decorator** dynamically adds/overrides behaviour in an existing method of an object.
* ✓✓ **Facade** provides a simplified interface to a large body of code.
* ✓✓ **Flyweight** reduces the cost of creating and manipulating a large number of similar objects.
* ✓✓ **Proxy** provides a placeholder for another object to control access, reduce cost, and reduce complexity.

## Genel Bakış: S.O.L.I.D.
* ✓✓ S -Single-responsiblity principle: Nesnenin sadece bir sorumluluğu olmalıdır, yani olası bir değişiklikte bunun tek bir sebebi olmalıdır.
* ✓✓ O -Open-closed principle: Nesne genişlemeye açık ancak değişikliklere kapalı olmalıdır.
* ✓✓ L -Liskov substitution principle: Programdaki nesnelerin, programın çalışmasında sorun yaratmadan kendi alt örnekleri ile değiştirilebilir olmasıdır.
* ✓✓ I -Interface segregation principle: Nesnelerin ihtiyaç duymadıkları metodların arayüzlerinden mümkün olduğunca ayrıştırılmasıdır.
* ✓✓ D -Dependency Inversion Principle: Yüksek seviyeli sınıflar, düşük seviyeli sınıflara bağlı olmamalı, her ikisi de soyut kavramlara bağlı olmalıdır.


## **Yükleme**
```bash
git clone https://github.com/ehvenimunis/CppCherno/tree/main/Desing%20Pattern
```

## **Kaynak**
> https://en.wikipedia.org/wiki/Design_Patterns 

> https://sourcemaking.com/

> https://www.geeksforgeeks.org

> https://cpppatterns.com

> https://www.codeproject.com/

> https://en.wikibooks.org/wiki/C++_Programming/Code/Design_Patterns

> http://simplestcodings.blogspot.com

> http://www.turtep.edu.tr/

> https://goalkicker.com/ - C++ Notes for Professionals book

> Design Patterns in Modern C++ - Dmitri Nesteruk

> Design Patterns Explained Simply - Alexander Shvets

> Modern C++ Design: Generic Programming and Design Patterns Applied - Andrei Alexandrescu
