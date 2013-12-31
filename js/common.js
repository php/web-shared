function cycle(to, from) {
    from.removeClass("current");
    to.addClass("current");
    $(window).scrollTop(to.offset().top);
}
function getNextOrPreviousSibling(node, forward) {
    if (forward) {
        return node.next();
    }
    return node.prev();
}
function cycleMenuItems(current, forward) {
    if (getNextOrPreviousSibling(current, forward).length) {
        cycle(getNextOrPreviousSibling(current, forward), current);
        curr.children("a").first().focus().css({outline: "none"});
    }
}
function cycleHeaders(matches, forward) {
    /* forward=1 next match
     * forward=0 previous match
     */
    var gotmatch = 0;

    matches.each(function(k, item) {
        if ($(item).hasClass("current")) {
            if ($(matches[forward ? k+1 : k-1]).length) {
                cycle($(matches[forward ? k+1 : k-1]), $(item));
                gotmatch = 1;
                return false;
            }
        }
    });
    if (!gotmatch) {
        cycle($(matches[forward ? 0 : matches.length-1]), $(matches[forward ? matches.length-1 : 0]));
    }
}
Mousetrap.bind('up up down down left right left right b a enter', function() {
    $(".home img").attr("src", "//php.net/images/php_konami.gif");
    $(window).scrollTop(0);
});
Mousetrap.bind("?", function() {
    $("#megadropdown").slideToggle();
});
Mousetrap.bind("esc", function() {
    $("#megadropdown").slideUp();
    $("#goto").slideUp();

    $("html").off("keydown");
    $("html").off("keypress");
});
Mousetrap.bind("G", function() {
    var n = $(document).height();
    $(window).scrollTop(n, 10);
});
Mousetrap.bind("g h", function() {
    window.location.href = "/";
});
Mousetrap.bind("g g", function() {
    $(window).scrollTop(0, 10);
});
Mousetrap.bind("g p", function() {
    var link = $("link[rel=prev]").attr("href");
    if (link) {
        window.location.href = link;
    }
});
Mousetrap.bind("g n", function() {
    var link = $("link[rel=next]").attr("href");
    if (link) {
        window.location.href = link;
    }
});

Mousetrap.bind("j", function() {
    /* Doc page */
    var node = $(".layout-menu .current");
    if (node.length) {
        cycleMenuItems(node, 1);
    }
    else {
        /* Cycle through headers on normal pages */
        var matches = $("section.fullscreen h1, section.fullscreen h2, section.fullscreen h3");
        cycleHeaders(matches, 1);
    }
});
Mousetrap.bind("k", function() {
    var node = $(".layout-menu .current");
    if (node.length) {
        cycleMenuItems(node, 0);
    }
    else {
        /* Cycle through headers on normal pages */
        var matches = $("section.fullscreen h1, section.fullscreen h2, section.fullscreen h3");
        cycleHeaders(matches, 0);
    }
});
Mousetrap.bind("/", function(e) {
    e.preventDefault();
    $("input[type=search]").focus()
});
var rotate = 0;
Mousetrap.bind("r o t a t e enter", function(e) {
    rotate += 90;
    if (rotate > 360) {
        rotate = 0;
    }
    $("html").css("-webkit-transform", "rotate(" + rotate + "deg)");
    $("html").css("-moz-transform",    "rotate(" + rotate + "deg)");
    $("html").css("-o-transform",      "rotate(" + rotate + "deg)");
    $("html").css("-ms-transform",     "rotate(" + rotate + "deg)");
    $("html").css("transform",         "rotate(" + rotate + "deg)");
});
var scale = 1;
Mousetrap.bind("m i r r o r enter", function(e) {
    scale *= -1;
    $("html").css("-webkit-transform", "scaleX(" + scale + ")");
    $("html").css("-moz-transform",    "scaleX(" + scale + ")");
    $("html").css("-o-transform",      "scaleX(" + scale + ")");
    $("html").css("-ms-transform",     "scaleX(" + scale + ")");
    $("html").css("transform",         "scaleX(" + scale + ")");
});
Mousetrap.bind("l o g o enter", function(e) {
    var time = new Date().getTime();
    $(".home img").attr("src", "//php.net/images/logo.php?refresh&time=" + time);
    $(window).scrollTop(0);
});


// vim: set ts=4 sw=4 et:
