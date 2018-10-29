/**
 * main.java
 * @author Jake Runyan
 * https://github.com/runyanjake/CodingPractice/Java/main.java
 */

import Animal.Dog;
import JScreen.JScreen;

public class main{
 public static void main(String args[]){
    Dog d = new Dog();
    d.name = "Barky";
    d.bark();
    Dog d2 = null;
    d2 = d;
    d2.name = "Barko";
    d2.bark();
    d.bark();

    
 }

}