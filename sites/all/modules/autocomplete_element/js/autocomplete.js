function acParseJson(data){

  var rows = new Array();

  for ( var i in data )
  {      
      rows.push({ data:data[i], value:data[i], result:i});
  }
  
  return rows;
  
}

function acFormatJson(row, i, n){

  return row;
  
}