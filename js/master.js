$(document).ready(function() {
  $('#votesdeleteform').submit(function() {
    if (confirm("Are you sure you want to delete these votes? This will permanently delete these votes from the votes table!"))
      return true;
    else
      return false;
  });
  $('#votesselectall').click(function() {
    if (this.checked) {
      $('input:checkbox.vdelids').each(function () {
           this.checked = true;
      });
    } else {
      $('input:checkbox.vdelids').each(function () {
           this.checked = false;
      });
    }
  });
});
