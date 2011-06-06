

<html>




<head>
 <link rel="stylesheet" type="text/css" media="screen,projection" href="http://housemedia.pl/sites/default/files/mapa/pl-mapa-240px.css" />
   <script type="text/javascript" src="http://ajax.googleapis.com/ajax/libs/jquery/1.4.4/jquery.min.js"></script>
   <script type="text/javascript" src="http://housemedia.pl/sites/default/files/mapa/pl-mapa.js"></script>
   <script type="text/javascript">//<![CDATA[
    $(function(){$('#options').find('a').click(function(){var klasa=$(this).text(); $('.switch').text(klasa); $('#mapa').removeClass().addClass(klasa+' script'); $(this).attr('href','#');}); $('#pl').find('li').click(function(){$('.active').removeClass(); $(this).find('a').addClass('active'); return false;});$('#pl').find('a').each(function(){if($(this).attr('href')===window.location.hash){$(this).addClass('active');}}); var scroll_timer; var displayed = false; var $message = $('#top-link'); var $window = $(window); var top = $(document.body).children(0).position().top; $window.scroll(function(){window.clearTimeout(scroll_timer);scroll_timer = window.setTimeout(function(){if($window.scrollTop() <= top){displayed = false;$message.fadeOut();}else if(displayed == false){displayed = true;$message.stop(true, true).fadeIn().click(function () { $message.fadeOut(); });}},100);});});
    //]]></script>
</head>
<body>
<div id="mapa" class="ukryta tooltip">
  <ul id="pl">
   <li id="pl1"><a href="#dolnoslaskie" title="Dolnośląskie">Dolnośląskie <span class="bg"></span></a></li>
   <li id="pl2"><a href="#kujawsko-pomorskie" title="Kujawsko-pomorskie">Kujawsko-pomorskie <span class="bg"></span></a></li>
   <li id="pl3"><a href="#lubelskie" title="Lubelskie">Lubelskie <span class="bg"></span></a></li>
   <li id="pl4"><a href="#lubuskie" title="Lubuskie">Lubuskie <span class="bg"></span></a></li>
   <li id="pl5"><a href="#lodzkie" title="Łódzkie">Łódzkie <span class="bg"></span></a></li>
   <li id="pl6"><a href="#malopolskie" title="Małopolskie">Małopolskie <span class="bg"></span></a></li>
   <li id="pl7"><a href="#mazowieckie" title="Mazowieckie">Mazowieckie <span class="bg"></span></a></li>
   <li id="pl8"><a href="#opolskie" title="Opolskie">Opolskie <span class="bg"></span></a></li>
   <li id="pl9"><a href="#podkarpackie" title="Podkarpackie">Podkarpackie <span class="bg"></span></a></li>
   <li id="pl10"><a href="#podlaskie" title="Podlaskie">Podlaskie <span class="bg"></span></a></li>
   <li id="pl11"><a href="#pomorskie" title="Pomorskie">Pomorskie <span class="bg"></span></a></li>
   <li id="pl12"><a href="#slaskie" title="Śląskie">Śląskie <span class="bg"></span></a></li>
   <li id="pl13"><a href="#swietokrzyskie" title="Świętokrzyskie">Świętokrzyskie <span class="bg"></span></a></li>
   <li id="pl14"><a href="#warminsko-mazurskie" title="Warmińsko-mazurskie">Warmińsko-mazurskie <span class="bg"></span></a></li>
   <li id="pl15"><a href="#wielkopolskie" title="Wielkopolskie">Wielkopolskie <span class="bg"></span></a></li>
   <li id="pl16"><a href="#zachodniopomorskie" title="Zachodniopomorskie">Zachodniopomorskie <span class="bg"></span></a></li>
  </ul>
 </div>
</body>
</html>