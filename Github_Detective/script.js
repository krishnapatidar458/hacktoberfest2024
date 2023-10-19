const wrapper = document.getElementsByClassName("wrapper");
const header = document.getElementsByClassName("header");
const icon =document.getElementById("mode-icon");

const mainContainer = document.querySelector(".main-container");
const container = document.getElementsByClassName("container");

const midData = document.getElementsByClassName("midData");
const container2 = document.getElementsByClassName("container-2");
const repo =document.getElementsByClassName("repo");
const repoNo =document.getElementsByClassName("repoNo");
const following = document.getElementsByClassName("following");
const followingNo = document.getElementsByClassName("followingNo");
const followers= document.getElementsByClassName("followers");
const followersNo= document.getElementsByClassName("followersNo");
const place = document.getElementsByClassName("place");
const bioLink = document.getElementsByClassName("bioLink");
const twitterLink = document.getElementsByClassName("twitterLink");
const officeName = document.getElementsByClassName("officeName");




mainContainer.classList.add("active");

const searchForm = document.querySelector("[data-searchPlace]");
const searchInput = document.querySelector("[data-searchInput]");



//adding event listener on the search bar and since form submit takes enter and click
searchForm.addEventListener("submit",(e)=>
{ 
    e.preventDefault();

    let userData  = searchInput.value;

    //input is userData
    if(userData===""){return;}

    else
    { 
        fetchUserInfo(userData);
    }

})



//fetching api to get data
async function fetchUserInfo(userData)
{ 
    
    mainContainer.classList.remove("active");
    // mainContainer.classList.remove("active");
    try{
        //url is let since we r concatenating userData
    let url = "https://api.github.com/users/";
    url+=userData;
    const response =  await fetch(url);
    const data = await response.json();
    renderUserInfo(data);
         mainContainer.classList.add("active");
    }

    catch (error) 
    {
        console.log(error.message);
    }

}

function checkNull(value, page) {
    if (value === null || value === undefined) {
      return "Not Available";
    } else {
      return value;
    }
  }

  
//rendering data got from api

function renderUserInfo(data)
{ 
//twitter.innerText = checkNull(data.twitter_username, twitter) ? data.twitter_username : "Not Available";
const githubImage =  document.querySelector("[data-githubImage]");
const userName = document.querySelector("[data-githubName]");
const githubLink = document.querySelector("[data-githubLink]");
const userDate = document.querySelector("[data-githubDate]") ;
const githubPara = document.querySelector("[data-githubPara]");
const RepoNo = document.querySelector("[data-RepoNo]");
const FollowersNo = document.querySelector("[data-FollowersNo]");
const FollowingNo = document.querySelector("[data-FollowingNo]");
const Place = document.querySelector("[data-Place]");
const page = document.querySelector("[data-email]");
const twitter = document.querySelector("[data-twitter]");
const company = document.querySelector("[data-office]");
const months = ["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"];


githubImage.src = `${data?.avatar_url}.png`;
//if in json format if like location:null then ===null
userName.innerText = data.login===null ? "Not available" : `${data?.name}`;
githubLink.innerText = data.login===null ? "Not available" : `@${data?.login}`;
githubLink.href = `${data?.html_url}`;

// for example-2023-07-05T12:34:56

// data.created.at_split at T after 05 .shift removes the time part from list
"2023-07-05"
"12:34:56"

datesegments = data.created_at.split("T").shift().split("-");
userDate.innerText = `Joined ${datesegments[2]} ${months[datesegments[1] - 1]} ${datesegments[0]}`;

githubPara.innerText = data.bio===null ? "There is no bio..." :`${data?.bio}`;

RepoNo.innerText = data.public_repos===null ? "Not availabe" : `${data?.public_repos}`;
FollowersNo.innertText = data?.followers;
FollowingNo.innerText = data?.following;

//if in json format if like location:"" then use checknull 
Place.innerText = data?.location;
page.href = data?.blog;

//checkNull function is above defined
page.innerText = checkNull(data.blog, page) ? data.blog : "Not Available";
//if in json format if like location:"" then use checknull 


twitter.href = checkNull(data.twitter_username, twitter) ? `https://twitter.com/${data.twitter_username}` : "#";
twitter.innerText = data.twitter_username===null ? "Not Available" : `${data.twitter_username}`;
company.innerText = checkNull(data.company, company) ? data.company : "Not Available";
}



