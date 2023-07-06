# Week 5

## Lab: [*Inheritance*](inheritance.c)

Complete the implementation of `inheritance.c`, such that it creates a family of a specified generation size and assigns blood type alleles to each family member. The oldest generation will have alleles assigned randomly to them.

- The `create_family` function takes an integer (`generations`) as input and should allocate (as via `malloc`) one `person` for each member of the family of that number of generations, returning a pointer to the `person` in the youngest generation.
  - For example, `create_family(3)` should return a pointer to a person with two parents, where each parent also has two parents.
  - Each `person` should have `alleles` assigned to them. The oldest generation should have alleles randomly chosen (as by calling the `random_allele` function), and younger generations should inherit one allele (chosen at random) from each parent.
  - Each `person` should have `parents` assigned to them. The oldest generation should have both `parents` set to `NULL`, and younger generations should have `parents` be an array of two pointers, each pointing to a different parent.

We’ve divided the `create_family` function into a few `TODO`s for you to complete.

- First, you should allocate memory for a new person. Recall that you can use `malloc` to allocate memory, and `sizeof(person)` to get the number of bytes to allocate.
- Next, we’ve included a condition to check if `generations > 1`.
  - If `generations > 1`, then there are more generations that still need to be allocated. We’ve already created two new `parents`, `parent0` and `parent1`, by recursively calling `create_family`. Your `create_family` function should then set the parent pointers of the new person you created. Finally, assign both `alleles` for the new person by randomly choosing one allele from each parent.
  - Otherwise (if `generations == 1`), then there will be no parent data for this person. Both `parents` of your new person should be set to `NULL`, and each `allele` should be generated randomly.
- Finally, your function should return a pointer for the `person` that was allocated.

The `free_family` function should accept as input a pointer to a `person`, free memory for that person, and then recursively free memory for all of their ancestors.

- Since this is a recursive function, you should first handle the base case. If the input to the function is `NULL`, then there’s nothing to free, so your function can return immediately.
- Otherwise, you should recursively `free` both of the person’s parents before `free`ing the child.


Upon running `./inheritance`, your program should adhere to the rules described in the background. The child should have two alleles, one from each parent. The parents should each have two alleles, one from each of their parents.

For example, in the example below, the child in Generation 0 received an O allele from both Generation 1 parents. The first parent received an A from the first grandparent and a O from the second grandparent. Similarly, the second parent received an O and a B from their grandparents.

```
$ ./inheritance
Child (Generation 0): blood type OO
    Parent (Generation 1): blood type AO
        Grandparent (Generation 2): blood type OA
        Grandparent (Generation 2): blood type BO
    Parent (Generation 1): blood type OB
        Grandparent (Generation 2): blood type AO
        Grandparent (Generation 2): blood type BO
```
        
## Problem Set

---
### [*Speller*](speller/speller.c)

Alright, the challenge now before you is to implement, in order, `load`, `hash`, `size`, `check`, and `unload` as efficiently as possible using a hash table in such a way that `TIME IN load`, `TIME IN check`, `TIME IN size`, and `TIME IN unload` are all minimized. To be sure, it’s not obvious what it even means to be minimized, inasmuch as these benchmarks will certainly vary as you feed `speller` different values for `dictionary` and for `text`. But therein lies the challenge, if not the fun, of this problem. This problem is your chance to design. Although we invite you to minimize space, your ultimate enemy is time. But before you dive in, some specifications from us.

- You may not alter `speller.c` or `Makefile`.
- You may alter `dictionary.c` (and, in fact, must in order to complete the implementations of `load`, `hash`, `size`, `check`, and `unload`), but you may not alter the declarations (i.e., prototypes) of `load`, `hash`, `size`, `check`, or `unload`. You may, though, add new functions and (local or global) variables to `dictionary.c`.
- You may change the value of `N` in `dictionary.c`, so that your hash table can have more buckets.
- You may alter `dictionary.h`, but you may not alter the declarations of `load`, `hash`, `size`, `check`, or `unload`.
- Your implementation of `check` must be case-insensitive. In other words, if `foo` is in dictionary, then `check` should return true given any capitalization thereof; none of `foo`, `foO`, `fOo`, `fOO`, `fOO`, `Foo`, `FoO`, `FOo`, and `FOO` should be considered misspelled.
- Capitalization aside, your implementation of `check` should only return `true` for words actually in `dictionary`. Beware hard-coding common words (e.g., `the`), lest we pass your implementation a `dictionary` without those same words. Moreover, the only possessives allowed are those actually in `dictionary`. In other words, even if `foo` is in `dictionary`, `check` should return `false` given `foo's` if `foo's` is not also in `dictionary`.
- You may assume that any `dictionary` passed to your program will be structured exactly like ours, alphabetically sorted from top to bottom with one word per line, each of which ends with `\n`. You may also assume that `dictionary` will contain at least one word, that no word will be longer than `LENGTH` (a constant defined in `dictionary.h`) characters, that no word will appear more than once, that each word will contain only lowercase alphabetical characters and possibly apostrophes, and that no word will start with an apostrophe.
- You may assume that `check` will only be passed words that contain (uppercase or lowercase) alphabetical characters and possibly apostrophes.
- Your spell checker may only take `text` and, optionally, `dictionary` as input. Although you might be inclined (particularly if among those more comfortable) to “pre-process” our default dictionary in order to derive an “ideal hash function” for it, you may not save the output of any such pre-processing to disk in order to load it back into memory on subsequent runs of your spell checker in order to gain an advantage.
- Your spell checker must not leak any memory. Be sure to check for leaks with `valgrind`.
- **The hash function you write should ultimately be your own, not one you search for online**. There are many ways to implement a hash function beyond using the first character (or characters) of a word. Consider a hash function that uses a sum of ASCII values or the length of a word. A good hash function tends to reduce “collisions” and has a fairly even distribution across hash table “buckets”.
- 
Alright, ready to go?

- Implement `load`.
- Implement `hash`.
- Implement `size`.
- Implement `check`.
- Implement `unload`.


How to check whether your program is outting the right misspelled words? Well, you’re welcome to consult the “answer keys” that are inside of the `keys` directory that’s inside of your speller directory. For instance, inside of `keys/lalaland.txt` are all of the words that your program *should* think are misspelled.

You could therefore run your program on some text in one window, as with the below.

```
./speller texts/lalaland.txt
```
And you could then run the staff’s solution on the same text in another window, as with the below.

```
./speller50 texts/lalaland.txt
```

## Practice Problems

---
### [*Trie*](trie/trie.c)

Learning Goals
- Learn more about data structures
- Work with a trie

Notice that the trie itself is implemented through the creative use of several `struct`s called `node`. Each `node` in a trie has an array of (potential) children, with size 26—one potential child for each letter of the alphabet! Adding words to this trie, notice that—for every letter in a word—we create a new `node` child whose parent is either the `root` node (for the first letter) or the previous letter (if not the first letter). On the very last letter, we set the `is_word` attribute of the child `node` to `true`. Now, checking if a word is in our trie is as easy as following each letter of that word through our trie. If we get to the final letter and see that `is_word` is true, well, that name is in our trie!

Your program should behave per the examples below.

```
trie/ $ ./trie dog_names.txt
Check word: Molly
Found!
```
```
trie/ $ ./trie dog_names.txt
Check word: Lucy
Found!
```
```
trie/ $ ./trie dog_names.txt
Check word: Prudence
Not Found.
```