
var lastIndex01 = 10000;
var lastIndex02 = 10000;
var lastIndex03 = 10000;
var lastIndex04 = 10000;

function scrollThumb(direction) {
  var child = document.getElementsByClassName('button-container')[0].offsetWidth;
  if (direction=='Go_L') {
      $('.scroll-menu-container').animate({
          scrollLeft: "-=" + child + "px"
      }, function(){
          // createCookie('scrollPos', $('#slide-wrap').scrollLeft());
      });
  }
  else if (direction=='Go_R') {
      $('.scroll-menu-container').animate({
          scrollLeft: "+=" + child + "px"
      }, function(){
          // createCookie('scrollPos', $('#slide-wrap').scrollLeft());
      });
  }
}

last = "Go_L";
function navButton(pos) {
  var child = document.getElementsByClassName('button-container')[0].offsetWidth;
  if (pos=='Go_L' && last == "Go_M") {
      $('.scroll-menu-container').animate({
          scrollLeft: "-=" + child + "px"
      }, function(){
          // createCookie('scrollPos', $('#slide-wrap').scrollLeft());
      });
  }
  else if (pos=='Go_L' && last == "Go_R") {
      $('.scroll-menu-container').animate({
          scrollLeft: "-=" + child*2 + "px"
      }, function(){
          // createCookie('scrollPos', $('#slide-wrap').scrollLeft());
      });
  }
  else if (pos=='Go_M' && last == "Go_R") {
      $('.scroll-menu-container').animate({
          scrollLeft: "-=" + child + "px"
      }, function(){
          // createCookie('scrollPos', $('#slide-wrap').scrollLeft());
      });
  }
  else if (pos=='Go_M' && last == "Go_L") {
      $('.scroll-menu-container').animate({
          scrollLeft: "+=" + child + "px"
      }, function(){
          // createCookie('scrollPos', $('#slide-wrap').scrollLeft());
      });
  }
  else if (pos=='Go_R' && last == "Go_L") {
      $('.scroll-menu-container').animate({
          scrollLeft: "+=" + child*2+ "px"
      }, function(){
          // createCookie('scrollPos', $('#slide-wrap').scrollLeft());
      });
  }
  else if (pos=='Go_R' && last == "Go_M") {
      $('.scroll-menu-container').animate({
          scrollLeft: "+=" + child+ "px"
      }, function(){
          // createCookie('scrollPos', $('#slide-wrap').scrollLeft());
      });
  }
  last = pos;
}

// $(document).ready( function() {


$(".01").click(function(){
  var index01 = $(".01").index(this);
  item = document.getElementsByClassName("01")[index01];
  item.style.backgroundColor = "#FF3055";
  item.style.color = "#1c1c1c";
  item.style.border = "none";

  // ---- send data from mode ------ //
  // document.getElementById("global-mode").innerHTML = index;
  // global_mode_val = index;
  // // send_request();
  // send_mode_request();
  // // ---- send data from mode ------ //
  //
  // // console.log("global mode: " + index);
  if (lastIndex01 == 10000) {
    lastIndex01 = index01;
    return;
  }
  else if (lastIndex01 == index01) {
    return;
  }
  else {
    console.log(lastIndex01);
    var lastItem = document.getElementsByClassName("01")[lastIndex01];
    lastItem.style.backgroundColor = "#272727";
    lastItem.style.color = "white";
    lastIndex01 = index01;
  }
});

$(".02").click(function(){
  var index02 = $(".02").index(this);
  item = document.getElementsByClassName("02")[index02];
  item.style.backgroundColor = "#FFC42D";
  item.style.color = "#1c1c1c";
  item.style.border = "none";

  if (lastIndex02 == 10000) {
    lastIndex02 = index02;
    return;
  }
  else if (lastIndex02 == index02) {
    return;
  }
  else {
    console.log(lastIndex02);
    var lastItem = document.getElementsByClassName("02")[lastIndex02];
    lastItem.style.backgroundColor = "#272727";
    lastItem.style.color = "white";
    lastIndex02 = index02;
  }
});

$(".03").click(function(){
  var index03 = $(".03").index(this);
  item = document.getElementsByClassName("03")[index03];
  item.style.backgroundColor = "#0CF477";
  item.style.color = "#1c1c1c";
  item.style.border = "none";

  if (lastIndex03 == 10000) {
    lastIndex03 = index03;
    return;
  }
  else if (lastIndex03 == index03) {
    return;
  }
  else {
    console.log(lastIndex03);
    var lastItem = document.getElementsByClassName("03")[lastIndex03];
    lastItem.style.backgroundColor = "#272727";
    lastItem.style.color = "white";
    lastIndex03 = index03;
  }
});

$(".04").click(function(){
  var index04 = $(".04").index(this);
  item = document.getElementsByClassName("04")[index04];
  item.style.backgroundColor = "#C660F5";
  item.style.color = "#1c1c1c";
  item.style.border = "none";

  if (lastIndex04 == 10000) {
    lastIndex04 = index04;
    return;
  }
  else if (lastIndex04 == index04) {
    return;
  }
  else {
    console.log(lastIndex04);
    var lastItem = document.getElementsByClassName("04")[lastIndex04];
    lastItem.style.backgroundColor = "#272727";
    lastItem.style.color = "white";
    lastIndex04 = index04;
  }
});


var toggle01 = false;
var toggle02 = false;
var toggle03 = false;
var toggle04 = false;

$(".01_").click(function(){
  var index01 = $(".01_").index(this);
  item = document.getElementsByClassName("01_")[index01];
  toggle01 = !toggle01;
  if (toggle01 == true) {
    item.style.backgroundColor = "#FF3055";
    item.style.color = "#1c1c1c";
    light01.settingSel = "true";
  }
  else {
    item.style.backgroundColor = "#272727";
    item.style.color = "white";
    light01.settingSel = "false";
  }
  console.log(light01);
});

$(".02_").click(function(){
  var index02 = $(".02_").index(this);
  item = document.getElementsByClassName("02_")[index02];
  toggle02 = !toggle02;
  if (toggle02 == true) {
    item.style.backgroundColor = "#FFC42D";
    item.style.color = "#1c1c1c";
    light02.settingSel = "true";
  }
  else {
    item.style.backgroundColor = "#272727";
    item.style.color = "white";
    light02.settingSel = "false";
  }
  console.log(light02);
});

$(".03_").click(function(){
  var index03 = $(".03_").index(this);
  item = document.getElementsByClassName("03_")[index03];
  toggle03 = !toggle03;
  if (toggle03 == true) {
    item.style.backgroundColor = "#0CF477";
    item.style.color = "#1c1c1c";
    light03.settingSel = "true";
  }
  else {
    item.style.backgroundColor = "#272727";
    item.style.color = "white";
    light03.settingSel = "false";
  }
  console.log(light03);
});

$(".04_").click(function(){
  var index04 = $(".04_").index(this);
  item = document.getElementsByClassName("04_")[index04];
  toggle04 = !toggle04;
  if (toggle04 == true) {
    item.style.backgroundColor = "#C660F5";
    item.style.color = "#1c1c1c";
    light04.settingSel = "true";
  }
  else {
    item.style.backgroundColor = "#272727";
    item.style.color = "white";
    light04.settingSel = "false";
  }
  console.log(light04);
});


$('.scroll-menu-container').scroll(function() {
  var music = document.getElementById("music-mode");
  var animation = document.getElementById("animation-mode");
  var settings = document.getElementById("light-settings");
  var grid = document.getElementsByClassName('grid')[0];

  var currX = $(this).scrollLeft();
  var postWidth = $(this).width();
	var scrollWidth = $('.button-container').width();
    // Current percentual position
  if (scrollWidth <= 1000) {
    var scrollPercent = (currX / ((scrollWidth - postWidth)))
    // if (scrollPercent >= 0 && scrollPercent < scrollWidth / 3) {
    //   console.log("1111111");
    //   music.style.color = "#ffffff";
    //   animation.style.color = "#777777";
    //   settings.style.color = "#777777";
    // }
    // else if (scrollPercent > scrollWidth / 3 && scrollPercent < (scrollWidth * 2) / 3) {
    //   console.log("2222222");
    //   music.style.color = "#777777";
    //   animation.style.color = "#ffffff";
    //   settings.style.color = "#777777";
    // }
    // else if (scrollPercent > (scrollWidth * 2) / 3 && scrollPercent <= scrollWidth) {
    //   console.log("3333333");
    //   music.style.color = "#777777";
    //   animation.style.color = "#777777";
    //   settings.style.color = "#ffffff";
    // }
    if (currX >= 0 && currX < scrollWidth) {
      console.log("1111111");
      music.style.color = "#ffffff";
      animation.style.color = "#777777";
      settings.style.color = "#777777";
    }
    else if (currX >= scrollWidth && currX < scrollWidth * 2) {
      console.log("2222222");
      music.style.color = "#777777";
      animation.style.color = "#ffffff";
      settings.style.color = "#777777";
    }
    else if (currX >= scrollWidth * 2 && currX < scrollWidth * 3) {
      console.log("3333333");
      music.style.color = "#777777";
      animation.style.color = "#777777";
      settings.style.color = "#ffffff";
    }
  }
  else {
    // var scrollPercent = (currX / ((scrollWidth - postWidth)))
    if (currX >= 0 && currX < scrollWidth) {
      console.log("1111111");
      music.style.color = "#ffffff";
      animation.style.color = "#777777";
      settings.style.color = "#777777";
    }
    else if (currX >= scrollWidth && currX < scrollWidth * 2) {
      console.log("2222222");
      music.style.color = "#777777";
      animation.style.color = "#ffffff";
      settings.style.color = "#777777";
    }
    else if (currX >= scrollWidth * 2 && currX < scrollWidth * 3) {
      console.log("3333333");
      music.style.color = "#777777";
      animation.style.color = "#777777";
      settings.style.color = "#ffffff";
    }
  }

  console.log(`scroll width ${scrollWidth}`);
  console.log(`scroll per ${scrollPercent}`);
  console.log(`post ${postWidth}`);
  console.log(`curx ${currX}`);
  // $('.bar-long').css('width', scrollPercent +"%"  );
});


// });


/*------------------------------------*/
  /*---------- color wheel -------------*/
  /*------------------------------------*/
