<?php

 require_once('includes/db.php');
 require_once('includes/functions.php');

 if($_SERVER["REQUEST_METHOD"] == "POST"){
    $title = prep_data($_POST['title']);
    $content = prep_data($_POST['content']);
    $star = prep_data($_POST['star']);
    $id = prep_data($_POST['id']);

    $sql = "UPDATE notes SET title='$title', content='$content', star='$star' WHERE id='$id' LIMIT 1";

    if(mysqli_query($conn, $sql)){
        header("Location: index.php");
    }
}

 if(!isset($_GET['id'])){
    header("Location: index.php");
 }
 $id = $_GET['id'];
 $sql = "SELECT * FROM notes WHERE id ='" . $id . "' LIMIT 1";
 $result = mysqli_query($conn, $sql);
 $note = mysqli_fetch_assoc($result);
 mysqli_free_result($result);
 include_once('includes/header.php');
?>
    <div class="title-newPage text-left">
            
            <h3 class="ml-5">
                <a class="" href="index.php">
                    <svg width="1em" height="1em" viewBox="0 0 16 16" class="bi bi-arrow-left" fill="currentColor" xmlns="http://www.w3.org/2000/svg">
                    <path fill-rule="evenodd" d="M15 8a.5.5 0 0 0-.5-.5H2.707l3.147-3.146a.5.5 0 1 0-.708-.708l-4 4a.5.5 0 0 0 0 .708l4 4a.5.5 0 0 0 .708-.708L2.707 8.5H14.5A.5.5 0 0 0 15 8z"/>
                    </svg> 
                    Back
                </a>
            </h3> 

            <h3 class="text-center mb-5" style="color: rgb(21, 52, 109);">Edit Your Note</h3>
</div>

 <div class="form-container text-center">
    <form action="edit.php" method="post">   
        <input type="hidden" name="id" value= <?php echo $note['id']; ?>>  
        <div class="form-group">
            <label class="d-block">Title</label>
            <input type="text" name="title" value= <?php echo $note['title']; ?> />
        </div>
        
        <div class="form-group">
            <label class="d-block">Content</label>
            <textarea name="content"> <?php echo $note['content']; ?></textarea>
        </div>
        

        <div class="chkgroup">
            <span class="label-in">Star</span>
           <input type="hidden" name="star" value="0" />
            <input type="checkbox" name="star" value="1" <?php if($note['star']){ echo "checked";} ?> />
        </div>

        <input type="submit" />
    </form>
 </div>

</html>