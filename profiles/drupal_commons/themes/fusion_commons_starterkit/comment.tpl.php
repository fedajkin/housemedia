<?php
// $Id: comment.tpl.php 8347 2011-03-02 01:44:22Z sheena $
?>

<div class="comment <?php print $comment_classes;?> clear-block">

    <?php if ($comment->picture) :?>
  <div class="comment-picture">      
        <?php print $comment->picture; ?>
  </div>
      <?php endif; ?>
 
  <div class="comment-content-wrapper">
    <div class="comment-content">
      <h3 class="title"><?php print $title ?><?php if ($comment->new){ ?><a id="new"></a><span class="new"><?php print $new ?></span><?php } ?></h3>
      <div class="content">
      <div class="submitted">
        <?php print $submitted ?>
      </div>
        <?php print $content ?>
        <?php if ($signature): ?>
          <div class="signature">
            <?php print $signature ?>
          </div>
        <?php endif; ?>
      </div>
    </div>
  </div><!--/#comment-content-wrapper-->
<?php if ($links): ?>
  <div class="links">
    <?php print $links ?>
  </div>
<?php endif; ?>  
</div><!-- /comment -->
