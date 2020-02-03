// function send_light_request() {
//     var xhttp = new XMLHttpRequest();
//     var str = "hcbehcv";
//     console.log(str);
//     xhttp.open("GET", "setSTATE?STATEstate=" + str, true);
//     xhttp.send();
// }


$('.sendDataTest').on('click', function() {
    $.ajax({
      type: 'POST',
      url: '/sendTest',
      success: function(resultData) {
         console.log(resultData);
      }
    }).done(function ( data ) {
     console.log(data);
     }
  });
  // var lt = JSON.parse(listtest);
  // console.log(lt);
});
