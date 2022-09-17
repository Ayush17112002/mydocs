let addbtn = document.querySelector(".addTicket");
let modalCont = document.querySelector(".modal-container");
let txtarea = document.querySelector(".text-area");
let mainCont = document.querySelector(".main-container");
let priorityColors = document.querySelectorAll(".priority-containerColor");
let filterCont = document.querySelector(".filter");
let rembtn = document.querySelector(".action .remTicket");
let ticketsArr = [];
let colors = ["blue", "green","red","black"];
let colorid = 0;
let allTickets = null;

if(localStorage.getItem("jira-tickets")){
    //retrieve tickets from storage
    ticketsArr = JSON.parse(localStorage.getItem("jira-tickets"));
    console.log(ticketsArr);
    ticketsArr.forEach((ticket)=>{
        addTicket(ticket.text, ticket.color, ticket.id);
    })
}
//pop up the modal container on clicking over the add button
addbtn.addEventListener("click",(e)=>{
    let val = modalCont.style.display;
    if(val === "none"){
        modalCont.style.display = "flex";
    }else{
        modalCont.style.display = "none";
    }
})


//insert ticket onto the display
function addTicket(txt, clr, myid){
    let tmpid;
    if(myid === undefined) tmpid = shortid();
    else tmpid = myid;
    let newEle = document.createElement("div");
    newEle.setAttribute("class", "ticket-container");
    newEle.innerHTML = `
        <div class="id ${clr}">#${tmpid}</div>
        <div class="task">${txt}</div>
        <div class="lock"><i class="fa-solid fa-lock"></i></div>`
    ;
    mainCont.appendChild(newEle);
    if(!myid){
        ticketsArr.push({
        id : tmpid,
        text : txt,
        color : clr
    }); 
    localStorage.setItem("jira-tickets",JSON.stringify(ticketsArr));
    }
    handleLock(newEle);
    handleId(newEle);
    handleFilter(newEle);
}

//creating a new ticket 
txtarea.addEventListener("keydown",(e)=>{
    console.log("text");
    let key = e.key;
    if(key === "Shift"){
        if(!txtarea.value) return;
        addTicket(txtarea.value, colors[colorid]);
        txtarea.value="";
        priorityColors.forEach((color,id)=>{
            color.classList.remove("border");
        });
        priorityColors[priorityColors.length-1].classList.add("border");
        modalCont.style.display = "none";
        colorid = 3;
    }
})

//for each function will take 
//1st arg-> element of the array
//2nd arg-> index of that element
priorityColors.forEach((color,id)=>{
    color.addEventListener("click",(e)=>{
        priorityColors.forEach((curr)=>{
            curr.classList.remove("border");
        })
        color.classList.add("border");
        colorid = id;
    })
});

//to perform lock functionality
//accessing 'lock' dynamic div using func.. dont't understand why?
function handleLock(myticket){
    let task = myticket.querySelector(".task");
    let myid = myticket.querySelector(".id");
    let lockClass = "fa-lock";
    let unlockClass = "fa-lock-open";
    let mylock = myticket.querySelector(".lock");
    console.log(mylock);
    mylock = mylock.children[0];
    mylock.addEventListener("click",(e)=>{
        let clsEle = mylock.classList;
        if(clsEle[1] === lockClass){
            mylock.classList.remove(lockClass);
            mylock.classList.add(unlockClass);
            task.setAttribute("contenteditable","true");
        }else{
            mylock.classList.remove(unlockClass);
            mylock.classList.add(lockClass);
            task.setAttribute("contenteditable","false");
        }
        ticketsArr.forEach((ticket)=>{
            if(ticket.id === myid){
                ticket.task = task.textContent;
                localStorage.setItem("jira-tickets",JSON.stringify(ticketsArr));
            }
        })
    })
}

//color on id shud be clickable
function handleId(myticket){
    let idEle = myticket.querySelector(".id");
    let mycolor = idEle.classList[1];
    let mycolorid;
    for(let i = 0; i < 4; i++){
        if(colors[i] == mycolor){
            mycolorid=i;
            break;
        }
    } 
    idEle.addEventListener("click",(e)=>{
        mycolorid+=1;
        mycolorid%=4;
        console.log(mycolorid);
        idEle.classList.remove(mycolor);
        idEle.classList.add(colors[mycolorid]);
        mycolor = colors[mycolorid];
    })
}

//functionality of filtering contents
function handleFilter(myticket){
    let mycolors = filterCont.querySelectorAll(".color");
    mycolors.forEach((currColor)=>{
        currColor.addEventListener("click",(e)=>{
            let tkt = myticket.querySelector(".id");
            let ticketcolor = tkt.classList[1];
            let colorshouldbe = currColor.classList[0];
            if(ticketcolor === colorshouldbe){
                myticket.style.display = "flex";
            }else{
                myticket.style.display = "none";
            }
        })
        currColor.addEventListener("dblclick",(e)=>{
            myticket.style.display = "flex";
        });
    })
}