const fetchData = async (endpoint) =>{
    const response = await fetch(`https://jsonplaceholder.typicode.com/${endpoint}`);
    return  response.json();
}

const parallel = async () =>{
    const usersData = await fetchData("users");
    console.log(usersData);

    const todosData = fetchData("todos");
    const [response1, response2] = await Promise.all([usersData, todosData]);
    //console.log(response1, response2);
}

parallel();