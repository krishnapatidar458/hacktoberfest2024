<?php

 require_once('includes/db.php');
 require_once('includes/functions.php');
 include_once('includes/header.php');

 if($_SERVER["REQUEST_METHOD"] == "POST"){
     $title = prep_data($_POST['title']);
     $content = prep_data($_POST['content']);
     $star = prep_data($_POST['star']);

     $sql = "INSERT INTO notes (title, content, star) VALUES ('$title', '$content', '$star')";
     
     if(mysqli_query($conn, $sql)){
        header("Location: index.php");
     }
 }

?>


    <div class="title-newPage text-left ml-5">
            
                <h3>
                    <a class="" href="index.php">
                        <svg width="1em" height="1em" viewBox="0 0 16 16" class="bi bi-arrow-left" fill="currentColor" xmlns="http://www.w3.org/2000/svg">
                        <path fill-rule="evenodd" d="M15 8a.5.5 0 0 0-.5-.5H2.707l3.147-3.146a.5.5 0 1 0-.708-.708l-4 4a.5.5 0 0 0 0 .708l4 4a.5.5 0 0 0 .708-.708L2.707 8.5H14.5A.5.5 0 0 0 15 8z"/>
                        </svg> 
                         Back
                    </a>
                </h3> 
            
    </div>

    <div class="form-container text-center">
    <form action="new.php" method="post">     
        <div class="form-group">
            <label class="d-block">Title</label>
            <input type="text" name="title" />
        </div>
        
        <div class="form-group">
            <label class="d-block">Content</label>
            <textarea name="content"> </textarea>
        </div>
        

        <div class="chkgroup">
            <span class="label-in">Star</span>
           <input type="hidden" name="star" value="0" />
            <input type="checkbox" name="star" value="1" />
        </div>

        <input type="submit" />
    </form>
    </div>
    
</html>

<?php

 require_once('includes/footer.php');

?>