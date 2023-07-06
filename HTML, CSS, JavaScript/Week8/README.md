# [Week 8](../../README.md)

## Lab: [Trivia](trivia/index.html)

Design a webpage using HTML, CSS, and JavaScript to let users answer trivia questions.


  - In `index.html`, add beneath “Part 1” a multiple-choice trivia question of your choosing with HTML.
    
      - You should use an `h3` heading for the text of your question.
      - You should have one `button` for each of the possible answer choices. There should be at least three answer choices, of which exactly one should be correct.
    
  
  - Using JavaScript, add logic so that the buttons change colors when a user clicks on them.
    
      - If a user clicks on a button with an incorrect answer, the button should turn red and text should appear beneath the question that says “Incorrect”.
      - If a user clicks on a button with the correct answer, the button should turn green and text should appear beneath the question that says “Correct!”.
    
  
  - In `index.html`, add beneath “Part 2” a text-based free response question of your choosing with HTML.
    
      - You should use an `h3` heading for the text of your question.
      - You should use an `input` field to let the user type a response.
      - You should use a `button` to let the user confirm their answer.
    
  
  - Using JavaScript, add logic so that the text field changes color when a user confirms their answer.
    
      - If the user types an incorrect answer and presses the confirmation button, the text field should turn red and text should appear beneath the question that says “Incorrect”.
      - If the user types the correct answer and presses the confirmation button, the input field should turn green and text should appear beneath the question that says “Correct!”.
    
  


Optionally, you may also:


  - Edit `styles.css` to change the CSS of your webpage!
  - Add additional trivia questions to your trivia quiz if you would like!


## Problem Set

---
### [Homepage](homepage/index.html)

Implement in your `homepage` directory a website that must:


  - Contain at least four different `.html` pages, at least one of which is `index.html` (the main page of your website), and it should be possible to get from any page on your website to any other page by following one or more hyperlinks.
  - Use at least ten (10) distinct HTML tags besides `<html>`, `<head>`, `<body>`, and `<title>`. Using some tag (e.g., `<p>`) multiple times still counts as just one (1) of those ten!
  - 
    Integrate one or more features from Bootstrap into your site. Bootstrap is a popular library (that comes with lots of CSS classes and more) via which you can beautify your site. See [Bootstrap’s documentation](https://getbootstrap.com/docs/5.2/) to get started. In particular, you might find some of [Bootstrap’s components](https://getbootstrap.com/docs/5.2/components/) of interest. To add Bootstrap to your site, it suffices to include

    ```
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.5.3/dist/css/bootstrap.min.css" integrity="sha384-TX8t27EcRE3e/ihU7zmQxVncDAy5uIKz4rEkgIXeMed4M0jlfIDPvg6uqKI2xXr2" crossorigin="anonymous">
    <script src="https://code.jquery.com/jquery-3.5.1.slim.min.js" integrity="sha384-DfXdz2htPH0lsSSs5nCTpuj/zy4C+OGpamoFVy38MVBnE+IbbVYUew+OrCXaRkfj" crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@4.5.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-ho+j7jyWK8fNQe+A12Hb8AhRq26LrZ/JpcUGGOn+Y7RsweNrtN/tE3MoK7ZeZDyx" crossorigin="anonymous"></script>
    ```

    in your pages’ `<head>`, below which you can also include

    ```
    <link href="styles.css" rel="stylesheet">
    ```

    to link your own CSS.
  
  - Have at least one stylesheet file of your own creation, `styles.css`, which uses at least five (5) different CSS selectors (e.g. tag (`example`), class (`.example`), or ID (`#example`)), and within which you use a total of at least five (5) different CSS properties, such as `font-size`, or `margin`; and
  - Integrate one or more features of JavaScript into your site to make your site more interactive. For example, you can use JavaScript to add alerts, to have an effect at a recurring interval, or to add interactivity to buttons, dropdowns, or forms. Feel free to be creative!
  - Ensure that your site looks nice on browsers both on mobile devices as well as laptops and desktops.
