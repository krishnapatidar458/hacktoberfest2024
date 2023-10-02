<?php

 require_once('includes/db.php');
 $sql = "SELECT * FROM notes";
 $notes = mysqli_query($conn, $sql);
 include_once('includes/header.php');

?>
            <hr>
                <div class="row col-container m-0">
                    <?php
                        while($note = mysqli_fetch_assoc($notes)){
                    ?>
                    <div class="col-lg-3 col-md-10 col-sm-12 m-md-5 col m-3 note">
                    <div class="">
                        <div class="row title-container"> 
                            <div class="col-10">
                                <h2 class="h3-title"><?php echo $note['title']; ?></h2>
                            </div>
                            <div class="col-1 text-right">
                                <?php if($note['star'] == 1){
                                  echo '<svg width="1.5em" height="1.5em" viewBox="0 0 16 16" class="bi bi-star-fill" fill="yellow" xmlns="http://www.w3.org/2000/svg">
                                  <path d="M3.612 15.443c-.386.198-.824-.149-.746-.592l.83-4.73L.173 6.765c-.329-.314-.158-.888.283-.95l4.898-.696L7.538.792c.197-.39.73-.39.927 0l2.184 4.327 4.898.696c.441.062.612.636.283.95l-3.523 3.356.83 4.73c.078.443-.36.79-.746.592L8 13.187l-4.389 2.256z"/>
                                </svg>';}
                                 ?>
                            </div>
                            <div class="col-12">
                                <div class="row links">
                                   <a class="col-6 text-left h5" href=<?php echo 'edit.php?id='.$note['id']; ?>>edit note</a>
                                   <a class="col-6 text-right h5" href=<?php echo 'delete.php?id='.$note['id']; ?>>delete note</a>
                                </div>
                            </div>                 
                        </div>
                            <div class="row">
                                 <div class=" m-0 col-12 content-container">
                                      <?php echo $note['content']; ?>
                                 </div>
                            </div>
                            
                    </div>
                        
                </div>
            
                    <?php } 
                            mysqli_free_result($notes);
                    ?>
                </div>
                   
                    
                       
        
        <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
        <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/js/bootstrap.min.js" integrity="sha384-B4gt1jrGC7Jh4AgTPSdUtOBvfO8shuf57BaghqFfPlYxofvL8/KUEfYiJOMMV+rV" crossorigin="anonymous"></script>
    </body>
</html>

<?php

 require_once('includes/footer.php');

?>